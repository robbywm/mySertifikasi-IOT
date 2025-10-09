/*************************************************************
  Blynk adalah platform untuk mengontrol perangkat seperti ESP32,
  Arduino, Raspberry Pi, dll, melalui Internet.
  Info lebih lanjut: https://www.blynk.io
 *************************************************************/

#define BLYNK_TEMPLATE_ID "xxxxxxxxxxxxxxxxxxx"
#define BLYNK_TEMPLATE_NAME "xxxxxxxxx"

#define BLYNK_FIRMWARE_VERSION        "0.1.3"
#define BLYNK_PRINT Serial
#define APP_DEBUG

// Pilih board yang digunakan
#define USE_NODE_MCU_BOARD

// Pin LED dan buzzer
#define ledBiru D13
#define ledMerah D12
#define ledR D9
#define ledB D10
#define ledG D11
#define buzzerPin D5

// Library
#include "BlynkEdgent.h"
#include <DHT.h>

// DHT11
#define DHTPIN D4    
#define DHTTYPE DHT11  
#define pot A0
DHT dht(DHTPIN, DHTTYPE);

// Timer
BlynkTimer timer;

// Nilai kalibrasi dari slider V8
int calibrationSliderValue = 0;

void setup()
{
  Serial.begin(115200);
  delay(100);

  // Set pin output
  pinMode(ledBiru, OUTPUT);
  pinMode(ledMerah, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Mulai Blynk dan DHT
  BlynkEdgent.begin();
  dht.begin();

  // Set interval pembacaan sensor
  timer.setInterval(5000L, sensor_dht11);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}

// Kontrol LED dari aplikasi Blynk
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

// Fungsi pembacaan sensor DHT11
void sensor_dht11() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Kalibrasi suhu dengan nilai dari slider
  t += calibrationSliderValue;

  // Tampilkan di Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C\t");

  // Kirim ke Blynk
  Blynk.virtualWrite(V5, t);
  Blynk.virtualWrite(V6, h);

  // Jika suhu tinggi, aktifkan buzzer
  if (t >= 32) {
    for (int i = 0; i < 4; i++) { 
      tone(buzzerPin, 1000, 200); // bunyi 1kHz selama 200ms
      delay(400);  
    }
    Serial.print("Status: ");
    Serial.println("Melebihi Batas");
  } else {
    Serial.print("Status: ");
    Serial.println("Aman");  
  }
}

void analogInput(){
  int potValue = analogRead(pot);
  Blynk.virtualWrite(V7,potValue);
  //if(potValue >= 900){
  //tone(buzzerPin, 1000, 500); 
  //}
}

// Slider untuk kalibrasi suhu (Virtual Pin V8)
BLYNK_WRITE(V8)
{
  calibrationSliderValue = param.asInt(); // nilai dari -10 hingga +10
  Serial.print("Calibration value from V8: ");
  Serial.println(calibrationSliderValue);
}
