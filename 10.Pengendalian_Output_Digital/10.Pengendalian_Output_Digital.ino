// --- KREDENSIAL BLYNK ---
#define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
#define BLYNK_TEMPLATE_NAME "MySertifikasi"
#define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxx"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "NAMA_WIFI";
char pass[] = "SANDI_WIFI";

#define PIN_LED D4 // Status LED pada KasgarIoT Shield (Active LOW)

// Fungsi ini dieksekusi saat ada perubahan status pada Switch di Web Dashboard (V3)
BLYNK_WRITE(V3) {
  int statusSwitch = param.asInt(); 
  
  // Karena D4 bersifat Active LOW, logika dari Switch dibalik menggunakan '!'
  // statusSwitch = 1 (ON) akan menjadi LOW (0) pada pin fisik sehingga LED menyala
  digitalWrite(PIN_LED, !statusSwitch); 
  
  if(statusSwitch == 1) {
    Serial.println("Instruksi Diterima: LED NYALA");
  } else {
    Serial.println("Instruksi Diterima: LED MATI");
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, HIGH); // Kondisi awal mati (HIGH untuk Active LOW)
  
  Serial.println("Menghubungkan ke Blynk Cloud...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
}

