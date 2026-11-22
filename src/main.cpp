#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <math.h>
#include "config.h"
#ifndef WIFI_SSID
#define WIFI_SSID "YOUR_WIFI_NAME"
#endif
#ifndef WIFI_PASSWORD
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"
#endif
#ifndef THINGSPEAK_WRITE_API_KEY
#define THINGSPEAK_WRITE_API_KEY "YOUR_WRITE_API_KEY"
#endif
// Glowlogics Project 06. ACS712 mains-side installation MUST be done by a qualified electrician.
// ESP-01 TX -> D10; Uno D11 -> ESP-01 RX through 5V-to-3.3V level conversion.
static const uint8_t ACS_PIN=A1;
static const float SENSITIVITY=0.100f, OFFSET_V=2.5f, ADC_REF=5.0f, ADC_MAX=1023.0f;
static const float NOMINAL_MAINS_V=220.0f;
static const int SAMPLES=1000;
static const unsigned long UPLOAD_MS=30000UL;
LiquidCrystal_I2C lcd(0x27,16,2);
SoftwareSerial esp8266(10,11);
unsigned long lastUpload=0;

void drainEsp(){ while(esp8266.available()) Serial.write(esp8266.read()); }
void sendAT(const String &cmd,unsigned long waitMs=2000UL){
  esp8266.println(cmd); delay(waitMs); while(esp8266.available()) Serial.write(esp8266.read());
}
float readRMSCurrent(){
  double sumSq=0.0;
  for(int i=0;i<SAMPLES;i++){
    float voltage=(analogRead(ACS_PIN)*ADC_REF/ADC_MAX)-OFFSET_V;
    float current=voltage/SENSITIVITY;
    sumSq+=(double)current*current;
    delayMicroseconds(200);
  }
  return (float)sqrt(sumSq/SAMPLES);
}
void connectWifi(){
  sendAT(F("AT+RST"),3000);
  sendAT(F("AT+CWMODE=1"));
  sendAT(String(F("AT+CWJAP=\""))+WIFI_SSID+F("\",\"")+WIFI_PASSWORD+F("\""),8000);
}
void uploadThingSpeak(float currentA,float apparentVA){
  if(String(THINGSPEAK_WRITE_API_KEY)=="YOUR_WRITE_API_KEY"){
    Serial.println(F("Configure ThingSpeak Write API key privately.")); return;
  }
  sendAT(F("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80"));
  String request=String(F("GET /update?api_key="))+THINGSPEAK_WRITE_API_KEY+
    F("&field1=")+String(currentA,3)+F("&field2=")+String(apparentVA,1)+
    F(" HTTP/1.1\r\nHost: api.thingspeak.com\r\nConnection: close\r\n\r\n");
  sendAT(String(F("AT+CIPSEND="))+String(request.length()),1000);
  esp8266.print(request); delay(1500); drainEsp();
  sendAT(F("AT+CIPCLOSE"),500);
}
void setup(){
  Serial.begin(9600); esp8266.begin(9600); lcd.init(); lcd.backlight();
  lcd.setCursor(0,0); lcd.print(F("Energy Meter"));
  lcd.setCursor(0,1); lcd.print(F("Starting..."));
  Serial.println(F("Glowlogics Project 06 - Uno + ACS712 + ESP-01"));
  Serial.println(F("Apparent power = RMS current x assumed 220 V; not active power."));
  connectWifi();
  lcd.clear();
}
void loop(){
  float currentA=readRMSCurrent();
  float apparentVA=currentA*NOMINAL_MAINS_V;
  lcd.clear();
  lcd.setCursor(0,0); lcd.print(F("I=")); lcd.print(currentA,2); lcd.print(F("A"));
  lcd.setCursor(0,1); lcd.print(F("S=")); lcd.print(apparentVA,1); lcd.print(F("VA"));
  Serial.print(F("RMS current A=")); Serial.print(currentA,3);
  Serial.print(F(" | apparent VA=")); Serial.println(apparentVA,1);
  if(millis()-lastUpload>=UPLOAD_MS){ lastUpload=millis(); uploadThingSpeak(currentA,apparentVA); }
  delay(100);
}