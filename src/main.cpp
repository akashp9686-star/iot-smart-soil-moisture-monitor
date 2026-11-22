#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <math.h>
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
static const float SENSITIVITY=0.100f, ADC_REF=5.0f, ADC_MAX=1023.0f, NOMINAL_MAINS_V=230.0f;
static const unsigned long WINDOW_MS=1000UL, UPLOAD_MS=30000UL;
LiquidCrystal_I2C lcd(0x27,16,2);
SoftwareSerial esp8266(10,11);
unsigned long lastUpload=0;
void drainEsp(){ while(esp8266.available()) Serial.write(esp8266.read()); }
void at(const __FlashStringHelper *cmd,unsigned long waitMs=700){ esp8266.println(cmd); delay(waitMs); drainEsp(); }
float sampleRmsCurrent(){
  unsigned long start=millis(), n=0; double sum=0, sumSq=0;
  while(millis()-start<WINDOW_MS){ int v=analogRead(ACS_PIN); sum+=v; sumSq+=(double)v*v; ++n; }
  if(n<2) return 0;
  double mean=sum/n, variance=(sumSq/n)-(mean*mean); if(variance<0) variance=0;
  double rmsVolts=sqrt(variance)*ADC_REF/ADC_MAX;
  return (float)(rmsVolts/SENSITIVITY);
}
void connectWifi(){
  at(F("AT"),1000); at(F("AT+CWMODE=1"),1000);
  esp8266.print(F("AT+CWJAP=\"")); esp8266.print(WIFI_SSID);
  esp8266.print(F("\",\"")); esp8266.print(WIFI_PASSWORD); esp8266.println(F("\""));
  delay(8000); drainEsp();
}
void upload(float amps,float va){
  if(String(THINGSPEAK_WRITE_API_KEY)=="YOUR_WRITE_API_KEY"){ Serial.println(F("Configure ThingSpeak write key privately.")); return; }
  at(F("AT+CIPMUX=0"),500);
  esp8266.println(F("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80")); delay(2500); drainEsp();
  String req=String(F("GET /update?api_key="))+THINGSPEAK_WRITE_API_KEY+F("&field1=")+String(amps,3)+F("&field2=")+String(va,1)+F(" HTTP/1.1\r\nHost: api.thingspeak.com\r\nConnection: close\r\n\r\n");
  esp8266.print(F("AT+CIPSEND=")); esp8266.println(req.length()); delay(1000); esp8266.print(req); delay(4000); drainEsp(); at(F("AT+CIPCLOSE"),500);
}
void setup(){
  Serial.begin(9600); esp8266.begin(9600); lcd.init(); lcd.backlight();
  lcd.setCursor(0,0); lcd.print(F("Energy Meter")); lcd.setCursor(0,1); lcd.print(F("Starting..."));
  Serial.println(F("Glowlogics Project 06 - Uno + ACS712 + ESP-01"));
  Serial.println(F("Apparent power uses assumed 230 V; this is not active power."));
  connectWifi(); lcd.clear();
}
void loop(){
  float amps=sampleRmsCurrent(), va=amps*NOMINAL_MAINS_V;
  lcd.setCursor(0,0); lcd.print(F("I:")); lcd.print(amps,2); lcd.print(F(" A       "));
  lcd.setCursor(0,1); lcd.print(F("S:")); lcd.print(va,0); lcd.print(F(" VA      "));
  Serial.print(F("RMS A=")); Serial.print(amps,3); Serial.print(F(" apparent VA=")); Serial.println(va,1);
  if(millis()-lastUpload>=UPLOAD_MS){ lastUpload=millis(); upload(amps,va); }
}