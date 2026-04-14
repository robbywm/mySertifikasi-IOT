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

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);

  // Firmware V1: Menyalakan LED statis sebagai tanda program awal
  // Menggunakan LOW karena sirkuit Active LOW
  digitalWrite(PIN_LED, LOW); 

  // Koneksi ke Jaringan Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }

  // Konfigurasi Identitas OTA di Jaringan
  ArduinoOTA.setHostname("mySertifikasi-OTA");

  // Memulai Layanan OTA
  ArduinoOTA.begin();
}

void loop() {
  // Mendengarkan permintaan OTA dari jaringan
  ArduinoOTA.handle(); 
}

