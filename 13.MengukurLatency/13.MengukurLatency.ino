#define BLYNK_PRINT Serial

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "SESUAIKAN"
#define BLYNK_TEMPLATE_NAME "SESUAIKAN"
#define BLYNK_AUTH_TOKEN "SESUAIKAN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Kredensial WiFi dan Blynk
char ssid[] = "SESUAIKAN";
char pass[] = "SESUAIKAN";

BlynkTimer timer; // Object Timer agar tidak menggunakan delay()

unsigned long startPingTime; // Variabel penyimpan waktu kirim
bool isPinging = false;      // Status penanda sedang ping atau tidak

// --- Fungsi untuk Memulai Pengukuran Latency ---
void measureLatency() {
  if (!Blynk.connected()) return; // Pastikan terkoneksi dulu

  // 1. Catat waktu saat ini (Start Time)
  startPingTime = millis();
  isPinging = true;

  // 2. Kirim data dummy ke V09(Upload)
  // Kita kirim angka acak agar server memproses data baru
  int dummyData = random(0, 100); 
  Blynk.virtualWrite(V9, dummyData);

  // 3. Paksa Server mengirim balik nilai V9 ke perangkat (Download/Sync)
  // Inilah kunci pengujian Round Trip (Bolak-balik)
  Blynk.syncVirtual(V9);
}

// --- Handler ketika Server membalas data V9 ---
BLYNK_WRITE(V9) {
  // Fungsi ini dipanggil otomatis saat Blynk.syncVirtual(V9) berhasil dieksekusi server
  
  if (isPinging) {
    // 4. Hitung selisih waktu (End Time - Start Time)
    unsigned long latency = millis() - startPingTime;
    
    // 5. Tampilkan hasil ke Serial Monitor
    Serial.print("Latency (RTT): ");
    Serial.print(latency);
    Serial.println(" ms");

    // 6. Kirim nilai Latency ke Aplikasi Blynk (V10)
    Blynk.virtualWrite(V10, latency);

    isPinging = false; // Reset status
  }
}

void setup() {
  // Debug console
  Serial.begin(115200);

  // Koneksi ke Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // Jika menggunakan Server Lokal atau Custom:
  // Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);

  // Atur interval pengukuran setiap 2 detik (2000 ms)
  // JANGAN meletakkan ini di void loop() agar tidak membanjiri server (Flood Error)
  timer.setInterval(2000L, measureLatency);
}

void loop() {
  Blynk.run();
  timer.run(); // Jalankan timer
}
