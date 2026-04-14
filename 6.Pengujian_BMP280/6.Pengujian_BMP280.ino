#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; 

void setup() {
  Serial.begin(9600);
  Serial.println(F("Pengujian Sensor BMP280 Dimulai..."));

  if (!bmp.begin(0x76)) {
    Serial.println(F("Gagal menemukan sensor BMP280!"));
    Serial.println(F("Periksa pemasangan modul pada port I2C."));
    while (1); 
  }

  Serial.println(F("Sensor BMP280 Berhasil Diinisialisasi!"));

  // Pengaturan sampling standar untuk hasil yang stabil
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     
                  Adafruit_BMP280::SAMPLING_X2,     
                  Adafruit_BMP280::SAMPLING_X16,    
                  Adafruit_BMP280::FILTER_X16,      
                  Adafruit_BMP280::STANDBY_MS_500); 
}

void loop() {
  // 1. Membaca Suhu dalam derajat Celsius (*C)
  float suhu = bmp.readTemperature();
  
  // 2. Membaca Tekanan Udara (Pascal dibagi 100 menjadi hPa)
  float tekanan = bmp.readPressure() / 100.0F;

  // 3. Membaca Perkiraan Ketinggian (Meter)
  // 1013.25 adalah tekanan udara standar di permukaan laut (hPa)
  float ketinggian = bmp.readAltitude(1013.25);

  // Menampilkan hasil pembacaan ke Serial Monitor
  Serial.print(F("Suhu: "));
  Serial.print(suhu);
  Serial.print(F(" *C \t| "));
  
  Serial.print(F("Tekanan: "));
  Serial.print(tekanan);
  Serial.print(F(" hPa \t| "));
  
  Serial.print(F("Ketinggian: "));
  Serial.print(ketinggian);
  Serial.println(F(" m"));

  delay(2000);
}
