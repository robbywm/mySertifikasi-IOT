#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // I2C

void setup() {
  Serial.begin(115200);
  Serial.println(F("Tes Sensor BMP280 pada Wemos D1 R1"));

  if (!bmp.begin(0x76)) { // Ubah ke 0x77 jika modul anda berbeda address
    Serial.println("BMP280 tidak terdeteksi!");
    while (1); // Berhenti di sini jika tidak terbaca
  }

  // Konfigurasi Optional
  bmp.setSampling(
      Adafruit_BMP280::MODE_NORMAL,
      Adafruit_BMP280::SAMPLING_X2,    // Temperatur
      Adafruit_BMP280::SAMPLING_X16,   // Tekanan
      Adafruit_BMP280::FILTER_X16,
      Adafruit_BMP280::STANDBY_MS_500
  );
}

void loop() {
  Serial.print("Suhu: ");
  Serial.print(bmp.readTemperature());
  Serial.println(" °C");

  Serial.print("Tekanan: ");
  Serial.print(bmp.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Perkiraan Ketinggian: ");
  Serial.print(bmp.readAltitude(1013.25)); // sesuaikan tekanan referensi
  Serial.println(" m");

  Serial.println();
  delay(1000);
}