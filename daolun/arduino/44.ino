#include<SoftwareSerial.h>
#include <Wire.h> 
#include <Servo.h>
Servo myservo;
int pos = 0;

SoftwareSerial mySerial(3, 2);  // RX, TX

#define SSID           "Honor 9"                   // cannot be longer than 32 characters!

#define PASSWORD       "12345678"
#define HOST_PORT   (80)
#define HOST_NAME   F("api.heclouds.com")
static const byte  GETDATA[]  PROGMEM = {
  "GET https://api.heclouds.com/devices/505394835/datapoints?datastream_key&limit=1 HTTP/1.1\r\nHost:api.heclouds.com\r\napi-key:=9o1o=TKAbOIkeiUMaGhF6aS00o=\r\nConnection: close\r\n\r\n"
};


String postString;

#include "ESP8266.h"
ESP8266 wifi(mySerial); 

void setup() {
  myservo.attach(9);
  Serial.begin(9600); 
  while (!Serial) {;}
  Serial.println(F("hardware serial!"));
  mySerial.begin(115200);
  mySerial.println(F("software seria"));


while(wifi.setOprToStationSoftAP()==false){
Serial.print(F("waiting for setting operating mode station + softap ...\r\n"));
delay(100);
}
Serial.print(F("operating mode station + softap ok\r\n"));

while(wifi.joinAP(SSID, PASSWORD)==false){
Serial.print(F("waiting for joining AP...\r\n"));
delay(100);
}
Serial.print(F("Join AP success\r\n"));

while(wifi.disableMUX()==false){
Serial.print(F("waiting for single connecting mode TCP or UDP ...\r\n"));
delay(100);
}
Serial.print(F("single mode ok\r\n"));
Serial.print(F("setup success\r\n"));

}


void loop() {
wifi.createTCP(HOST_NAME,HOST_PORT);
while(wifi.createTCP(HOST_NAME,HOST_PORT)==false){
  Serial.print(F("waiting for tcp\r\n"));
delay(100);
}

Serial.print(F("tcp ok\r\n"));
 wifi.sendFromFlash(GETDATA, sizeof(GETDATA));

Serial.println(F("Send Success!"));

  uint8_t buffer[512] = {0};
  uint32_t len = wifi.recv(buffer, sizeof(buffer), 20000);
  if (len > 0)
  {
for (uint32_t i = 0; i < len; i++) {
if((char)buffer[i]=='a'&&(char)buffer[i+1]=='b'&&(char)buffer[i+2]=='c'&&(char)buffer[i+3]=='d'&&(char)buffer[i+4]=='e')
{
for(pos = 0; pos < 180; pos += 1){
myservo.write(pos);
delay(15);
for(pos = 180; pos>=1; pos-=1){
myservo.write(pos);
delay(15);
}  
}
}
}
}
  while(wifi.releaseTCP()==false){
Serial.print(F("waiting for release\r\n"));
delay(100);
}
}




