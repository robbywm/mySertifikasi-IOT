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
  
  Serial.println("Proses selesai. EEPROM bersih dari jejak konfigurasi lama.");
}

void loop() {
  // Tidak ada instruksi perulangan yang diperlukan
}