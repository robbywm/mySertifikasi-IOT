#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

// Kredensial Jaringan (Sangat disarankan menggunakan Mobile Hotspot Laptop/HP)
const char* ssid = "NAMA_WIFI_HOTSPOT_ANDA";
const char* password = "KATA_SANDI_HOTSPOT_ANDA";

// Sandi OTA: harus sama dengan sandi pada Firmware V1 (program 16)
const char* sandiOTA = "GANTI_SANDI_OTA";

// Definisi Pin Status LED pada KasgarIoT
// Catatan: LED D4 menggunakan logika Active LOW
#define PIN_LED D4

unsigned long waktuKedipTerakhir = 0;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);

  // Firmware V2: Matikan LED saat setup awal
  // Menggunakan HIGH karena sirkuit Active LOW
  digitalWrite(PIN_LED, HIGH);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }

  // Layanan OTA tetap wajib ada, agar perangkat masih bisa diperbarui lagi
  ArduinoOTA.setHostname("mySertifikasi-OTA");
  ArduinoOTA.setPassword(sandiOTA);
  ArduinoOTA.begin();
}

void loop() {
  ArduinoOTA.handle(); // Tetap wajib ada

  // --- Modifikasi Logika Indikator OTA (Firmware V2) ---
  // LED D4 berkedip tiap 500 ms sebagai bukti OTA berhasil.
  // Memakai millis() dan bukan delay(), supaya ArduinoOTA.handle()
  // tetap terpanggil terus dan permintaan OTA berikutnya tidak terlewat.
  if (millis() - waktuKedipTerakhir >= 500) {
    waktuKedipTerakhir = millis();
    digitalWrite(PIN_LED, !digitalRead(PIN_LED));
  }
  // ---------------------------------------------------
}
