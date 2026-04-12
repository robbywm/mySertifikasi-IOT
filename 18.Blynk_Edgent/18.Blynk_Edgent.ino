// --- Tab Utama: Edgent_ESP8266 (Firmware Versi 1.0) ---
#define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
#define BLYNK_TEMPLATE_NAME "mySertifikasi"

// VERSI AWAL: 0.1.0 (Belum Dikalibrasi Spesifik)
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#define USE_KASGARIOT_SHIELD

#include "BlynkEdgent.h"
#include <DHT.h>

// Definisi DHT22 pada KasgarIoT Shield (Pin D5)
#define DHTPIN D5
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

// Fungsi Pembacaan Sensor Suhu (Virtual Pin V0)
void kirimDataSuhu() {
  float suhuStandar = dht.readTemperature();
  
  if (isnan(suhuStandar)) {
    Serial.println("Gagal membaca dari sensor DHT!");
    return;
  }
  
  Blynk.virtualWrite(V0, suhuStandar);
  Serial.print("Versi 1.0 Berjalan. Suhu Standar: ");
  Serial.print(suhuStandar);
  Serial.println(" *C");
}

void setup()
{
  Serial.begin(115200);
  delay(100);
  
  dht.begin();
  BlynkEdgent.begin();
  
  // Timer mengirim data suhu setiap 2 detik
  timer.setInterval(2000L, kirimDataSuhu);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}
