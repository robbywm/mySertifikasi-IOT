#define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
#define BLYNK_TEMPLATE_NAME "MySertifikasi"

// VERSI PEMBARUAN MAYOR (INTEGRASI SISTEM)
#define BLYNK_FIRMWARE_VERSION        "0.2.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#define USE_KASGARIOT_SHIELD

#include "BlynkEdgent.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <DHT.h>

// --- Definisi Pin KasgarIoT Shield R1 ---
#define PIN_LED D4       
#define PIN_TOMBOL D3   
#define PIN_ANALOG A0    
#define DHTPIN D5       
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP280 bmp;
BlynkTimer timer;

int statusTombolTerakhir = HIGH; 

BLYNK_WRITE(V3) {
  int statusSwitch = param.asInt();
  // Inversi (!) karena rangkaian D4 bersifat Active LOW
  digitalWrite(PIN_LED, !statusSwitch); 
}

// 1. Fungsi Cepat: Mengecek input Tombol (Dieksekusi tiap 100 milidetik)
void cekTombol() {
  int statusTombolSekarang = digitalRead(PIN_TOMBOL);
  
  if (statusTombolSekarang != statusTombolTerakhir) {
    delay(50); 
    int statusValid = digitalRead(PIN_TOMBOL);
    
    if (statusValid == statusTombolSekarang) {
      int nilaiKirim = !statusValid; 
      Blynk.virtualWrite(V4, nilaiKirim);
      statusTombolTerakhir = statusValid; 
      
      if(nilaiKirim == 1){
        Serial.println("Tombol Fisik Ditekan!");
      }
    }
  }
}

// 2. Fungsi Lambat: Pengiriman Data Sensor (Dieksekusi tiap 2 Detik)
void kirimDataSensor() {
  int nilaiPot = analogRead(PIN_ANALOG);
  Blynk.virtualWrite(V5, nilaiPot);

  // Baca DHT22 (V0 Suhu, V1 Kelembapan)
  float kelembapan = dht.readHumidity();
  float suhu = dht.readTemperature();
  if (!isnan(kelembapan) && !isnan(suhu)) {
    Blynk.virtualWrite(V0, suhu);
    Blynk.virtualWrite(V1, kelembapan);
  }

  // Baca BMP280 (V2 Tekanan Udara)
  float tekanan = bmp.readPressure() / 100.0F; 
  if (tekanan > 0) {
    Blynk.virtualWrite(V2, tekanan);
  }
  
  Serial.println("Data Sensor (DHT, BMP, Potensiometer) Berhasil Dikirim.");
}

void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, HIGH);
  pinMode(PIN_TOMBOL, INPUT_PULLUP);

  dht.begin();
  if (!bmp.begin(0x76)) {
    Serial.println("PERINGATAN: Gagal menemukan sensor BMP280!");
  }

  BlynkEdgent.begin();
  timer.setInterval(100L, cekTombol);
  timer.setInterval(2000L, kirimDataSensor);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}

