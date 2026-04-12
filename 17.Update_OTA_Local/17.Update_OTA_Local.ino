#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

// Kredensial Jaringan (Sangat disarankan menggunakan Mobile Hotspot Laptop/HP)
const char* ssid = "NAMA_WIFI_HOTSPOT_ANDA";
const char* password = "KATA_SANDI_HOTSPOT_ANDA";

// Definisi Pin Status LED pada KasgarIoT
// Catatan: LED D4 menggunakan logika Active LOW
#define PIN_LED D4

// ... [Bagian atas kode kredensial dan library tetap sama] ...

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

  ArduinoOTA.setHostname("mySertifikasi-OTA");
  ArduinoOTA.begin();
}

void loop() {
  ArduinoOTA.handle(); // Tetap wajib ada

  // --- Modifikasi Logika Indikator OTA (Firmware V2) ---
  // Membuat LED D4 berkedip sebagai bukti OTA berhasil
  digitalWrite(PIN_LED, LOW);  // LED Menyala
  delay(500);
  digitalWrite(PIN_LED, HIGH); // LED Padam
  delay(500);
  // ---------------------------------------------------
}