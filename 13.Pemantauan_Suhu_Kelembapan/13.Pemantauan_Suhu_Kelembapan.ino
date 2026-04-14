// --- KREDENSIAL BLYNK ---
#define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
#define BLYNK_TEMPLATE_NAME "MySertifikasi"
#define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxx"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char ssid[] = "NAMA_WIFI";
char pass[] = "SANDI_WIFI";

// Konfigurasi Sensor DHT
#define DHTPIN D5
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

void kirimDataDHT() {
  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity();

  if (isnan(suhu) || isnan(kelembapan)) {
    Serial.println("Peringatan: Gagal mengakuisisi data dari DHT22");
    return;
  }

  Serial.print("Suhu: "); Serial.print(suhu); Serial.print(" C | ");
  Serial.print("Kelembapan: "); Serial.print(kelembapan); Serial.println(" %");

  Blynk.virtualWrite(V0, suhu);
  Blynk.virtualWrite(V1, kelembapan);
}

void setup() {
  Serial.begin(9600);
  
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  timer.setInterval(2000L, kirimDataDHT); // Siklus pembacaan tiap 2 detik
}

void loop() {
  Blynk.run();
  timer.run();
}
