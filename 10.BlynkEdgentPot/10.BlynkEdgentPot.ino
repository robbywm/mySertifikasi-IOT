/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
 *************************************************************
  Blynk.Edgent implements:
  - Blynk.Inject - Dynamic WiFi credentials provisioning
  - Blynk.Air    - Over The Air firmware updates
  - Device state indication using a physical LED
  - Credentials reset using a physical Button
 *************************************************************/

/* Fill in information from your Blynk Template here */
/* Read more: https://bit.ly/BlynkInject */
//#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
//#define BLYNK_TEMPLATE_NAME         "Device"
#define BLYNK_TEMPLATE_ID "TMPL6CXLGcRjg"
#define BLYNK_TEMPLATE_NAME "Wemos D1"

#define BLYNK_FIRMWARE_VERSION        "0.1.3"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI
#define ledBiru D13  //pin LED Biru
#define ledMerah D12 //pin LED Merah

#define ledR D9      //pin LED R
#define ledB D10     //pin LED G
#define ledG D11     //pin LED B

#include "BlynkEdgent.h"
#include <DHT.h>

#define DHTPIN D4    
#define DHTTYPE DHT11  
//ANALOG INPUT
#define pot A0 

DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

void setup()
{
  Serial.begin(115200);
  delay(100);

  pinMode(ledBiru, OUTPUT);
  pinMode(ledMerah, OUTPUT);

  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  BlynkEdgent.begin();
  dht.begin();
  timer.setInterval(5000L, sensor_dht11);
  //ANALOG INPUT
  timer.setInterval(1000L, analogInput);
}

void loop() {
  BlynkEdgent.run();
    timer.run();
}

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  Serial.print("V0 Switch value is: ");
  Serial.println(pinValue);

  digitalWrite(ledBiru, pinValue);
}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  Serial.print("V1 Switch value is: ");
  Serial.println(pinValue);

  digitalWrite(ledMerah, pinValue);
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();
  Serial.print("V2 Switch value is: ");
  Serial.println(pinValue);

  digitalWrite(ledR, pinValue);
}

BLYNK_WRITE(V3)
{
  int pinValue = param.asInt();
  Serial.print("V3 Switch value is: ");
  Serial.println(pinValue);

  digitalWrite(ledG, pinValue);
}

BLYNK_WRITE(V4)
{
  int pinValue = param.asInt();
  Serial.print("V4 Switch value is: ");
  Serial.println(pinValue);

  digitalWrite(ledB, pinValue);
}

void sensor_dht11(){
  int potValue = analogRead(A0);
  float calibrationValue = map(potValue, 0, 1023, -10, 10);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  t += calibrationValue;

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");

  Blynk.virtualWrite(V5,t);
  Blynk.virtualWrite(V6,h);
}

void analogInput(){
  int potValue = analogRead(pot);
  Blynk.virtualWrite(V7,potValue);
}
