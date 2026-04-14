#include "DHT.h"
#define DHTPIN D5       // Pin D5 pada Wemos D1 R2
#define DHTTYPE DHT22   // Tipe sensor DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Pengujian Sensor DHT22 Dimulai...");
  dht.begin();
}

void loop() {
  delay(2000);
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Validasi apakah pembacaan berhasil
  if (isnan(h) || isnan(t)) {
    Serial.println("Gagal membaca dari sensor DHT!");
    return;
  }
  Serial.print("Kelembapan: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Suhu: ");
  Serial.print(t);
  Serial.println(" *C");
}