// --- KREDENSIAL BLYNK ---
#define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
#define BLYNK_TEMPLATE_NAME "MySertifikasi"
#define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxx"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "NAMA_WIFI";
char pass[] = "SANDI_WIFI";

#define PIN_TOMBOL 0 // User Button pada KasgarIoT (Active LOW)

BlynkTimer timer;

void kirimStatusTombol() {
  // Karena Active LOW, tombol ditekan = 0 (LOW), dilepas = 1 (HIGH). 
  // Kita balik logikanya dengan (!) agar di Dashboard bernilai 1 saat ditekan.
  int status = !digitalRead(PIN_TOMBOL); 
  
  Blynk.virtualWrite(V4, status);
  Serial.print("Status Tombol dikirim: ");
  Serial.println(status == 1 ? "DITEKAN" : "DILEPAS");
}

void setup() {
  Serial.begin(9600);
  pinMode(PIN_TOMBOL, INPUT_PULLUP);
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(500L, kirimStatusTombol); // Alokasi timer interval
}

void loop() {
  Blynk.run();
  timer.run(); // Eksekusi timer
}
