#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  
  // Mengalokasikan 512 bytes memori Flash untuk emulasi EEPROM
  EEPROM.begin(512); 
  
  Serial.println();
  Serial.println("Memulai proses pembersihan memori EEPROM...");

  // Melakukan perulangan untuk menulis nilai 0 pada setiap alamat byte
  for (int i = 0; i < 512; i++) {
    EEPROM.write(i, 0);
  }

  // Menyimpan perubahan secara permanen ke memori Flash
  EEPROM.commit(); 
  
  Serial.println("EEPROM bersih dari jejak konfigurasi lama.");

  // Bila program lama memakai WiFi.persistent(true), SSID dan password disimpan
  // SDK di sektor konfigurasi tersendiri (di luar EEPROM), jadi dihapus terpisah
  if (ESP.eraseConfig()) {
    Serial.println("Kredensial WiFi yang disimpan SDK juga sudah dihapus.");
  } else {
    Serial.println("Peringatan: Kredensial WiFi SDK gagal dihapus.");
  }
  Serial.println("Proses selesai.");
}

void loop() {
  // Tidak ada instruksi perulangan yang diperlukan
}