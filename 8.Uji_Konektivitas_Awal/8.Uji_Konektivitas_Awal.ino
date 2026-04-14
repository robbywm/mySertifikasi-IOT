// --- KREDENSIAL BLYNK ---
#define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
#define BLYNK_TEMPLATE_NAME "MySertifikasi"
#define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxx"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "NAMA_WIFI";
char pass[] = "SANDI_WIFI";

void setup() {
  Serial.begin(9600);
  Serial.println("Memulai uji koneksi ke Blynk Cloud...");
  
  // Fungsi ini akan melakukan koneksi WiFi sekaligus otentikasi Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
}
