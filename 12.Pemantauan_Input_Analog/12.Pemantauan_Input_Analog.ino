// --- KREDENSIAL BLYNK ---
#define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
#define BLYNK_TEMPLATE_NAME "MySertifikasi"
#define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxx"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "NAMA_WIFI";
char pass[] = "SANDI_WIFI";

#define PIN_ANALOG A0 // Potensiometer pada KasgarIoT Shield

BlynkTimer timer;

void kirimDataAnalog() {
  int nilaiADC = analogRead(PIN_ANALOG); // Rentang nilai 0 - 1023
  
  Blynk.virtualWrite(V5, nilaiADC);
  Serial.print("Nilai Potensiometer (ADC): ");
  Serial.println(nilaiADC);
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  timer.setInterval(1000L, kirimDataAnalog); // Kirim data setiap 1 detik
}

void loop() {
  Blynk.run();
  timer.run();
}

