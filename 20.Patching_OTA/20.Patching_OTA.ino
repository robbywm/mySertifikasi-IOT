// --- Tab Utama: Edgent_ESP8266 (Firmware Versi 1.1 - PATCH TERKALIBRASI) ---

#define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
#define BLYNK_TEMPLATE_NAME "mySertifikasi"

// NAIKKAN VERSI FIRMWARE MENJADI 0.1.1!
#define BLYNK_FIRMWARE_VERSION        "0.1.1"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#define USE_KASGARIOT_SHIELD

#include "BlynkEdgent.h"
#include <DHT.h>

#define DHTPIN D5
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

void kirimDataSuhu() {
  float suhuStandar = dht.readTemperature();
  
  if (isnan(suhuStandar)) {
    Serial.println("Gagal membaca dari sensor DHT!");
    return;
  }
  
  // [SIMULASI PATCH] Menambahkan offset kalibrasi sebesar -2.5
  float offsetKalibrasi = -2.5; 
  float suhuTerkalibrasi = suhuStandar + offsetKalibrasi;
  
  Blynk.virtualWrite(V0, suhuTerkalibrasi);
  Serial.print("Versi 1.1 (Patch Terkalibrasi). Suhu Aktual: ");
  Serial.print(suhuTerkalibrasi);
  Serial.println(" *C");
}

void setup()
{
  Serial.begin(115200);
  delay(100);
  
  dht.begin();
  BlynkEdgent.begin();
  
  timer.setInterval(2000L, kirimDataSuhu);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}
