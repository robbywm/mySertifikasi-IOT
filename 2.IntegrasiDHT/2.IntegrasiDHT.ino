//Kode program Wemos D1 R1

#include "DHT.h"            //Library DHT

#define DHTPIN D4            //Inisialisasi DHT pada pin D4
#define DHTTYPE DHT11       //Inisialisasi tipe DHT

DHT dht (DHTPIN,DHTTYPE);   //Mengenalkan pin dan tipe DHT

void setup(){
  Serial.begin(9600);
  Serial.println("Wemos D1 R1 Ready to Test");
  
  dht.begin();
}
  
void sensor_dht11(){
  float h = dht.readHumidity(); //Variabel penampung nilai suhu
  float t = dht.readTemperature(); //Variabel penampung nilai kelembaban
  
  if (isnan(h) || isnan(t)) {
    Serial.println("Gagal Membaca Sensor DHT!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
}

void loop(){
  sensor_dht11();
  delay(1000);
}
