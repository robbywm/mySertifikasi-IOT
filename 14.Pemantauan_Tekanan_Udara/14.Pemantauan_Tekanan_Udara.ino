// --- KREDENSIAL BLYNK ---
#define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
#define BLYNK_TEMPLATE_NAME "MySertifikasi"
#define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxx"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>

char ssid[] = "NAMA_WIFI";
char pass[] = "SANDI_WIFI";

Adafruit_BMP280 bmp; // Menggunakan bus I2C bawaan (D1, D2)

BlynkTimer timer;

void kirimDataBMP() {
  float tekanan = bmp.readPressure() / 100.0F;

  Serial.print("Tekanan Udara: "); Serial.print(tekanan); Serial.println(" hPa");

  Blynk.virtualWrite(V2, tekanan);
}

void setup() {
  Serial.begin(9600);
  
  if (!bmp.begin(0x76)) {
    Serial.println("Kesalahan Fatal: Sensor BMP280 tidak terdeteksi pada alamat 0x76");
  }

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, kirimDataBMP); // Siklus pembacaan tiap 2 detik
}

void loop() {
  Blynk.run();
  timer.run();
}
