// --- KREDENSIAL BLYNK ---
#define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
#define BLYNK_TEMPLATE_NAME "MySertifikasi"
#define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxx"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "NAMA_WIFI";
char pass[] = "SANDI_WIFI";

BlynkTimer timer;

// Fungsi untuk menguji dan menampilkan status jaringan secara berkala
void cekKoneksiJaringan() {
  // Menampilkan kekuatan sinyal WiFi (RSSI)
  long rssi = WiFi.RSSI();
  Serial.print("Kekuatan Sinyal WiFi (RSSI): ");
  Serial.print(rssi);
  Serial.println(" dBm");

  Serial.println("-----------------------------------");
}

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Memulai uji koneksi ke jaringan WiFi dan Blynk Cloud...");
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Menampilkan detail jaringan setelah terhubung
  Serial.println("===================================");
  Serial.print("Terhubung ke WiFi: ");
  Serial.println(WiFi.SSID());
  Serial.print("Alamat IP Perangkat: ");
  Serial.println(WiFi.localIP());
  Serial.println("Silakan catat nilai 'ping' di atas untuk analisis latency komunikasi data.");
  Serial.println("===================================");

  // Timer untuk cek kekuatan sinyal jaringan tiap 5 detik
  timer.setInterval(5000L, cekKoneksiJaringan);
}

void loop() {
  Blynk.run();
  timer.run();
}
