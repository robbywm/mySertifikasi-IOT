// OTA tanpa platform IoT: perangkat menarik firmware sendiri dari Supabase Storage.
//
// Cara kerja:
// 1. Perangkat membaca berkas version.txt dari bucket publik di Supabase Storage.
// 2. Jika isinya berbeda dari FW_VERSION, perangkat mengunduh firmware.bin
//    dari bucket yang sama, menulisnya ke flash, lalu restart.
//
// Bucket harus berisi DUA berkas: firmware.bin dan version.txt

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>
#include <WiFiClientSecureBearSSL.h>

// NAIKKAN versi ini setiap kali mengunggah firmware baru,
// dan tulis angka yang sama ke dalam version.txt
#define FW_VERSION "1.0.0"

const char* ssid = "NAMA_WIFI";
const char* password = "SANDI_WIFI";

// Proyek dan bucket Supabase tempat firmware disimpan (bucket harus public)
#define SB_PROJECT_REF "PROJECT_REF_SUPABASE" // Kode proyek, terlihat pada Project URL
#define SB_BUCKET      "firmware"

// Alamat berkas pada bucket publik. Tidak perlu API key.
const String URL_RILIS = String("https://") + SB_PROJECT_REF + ".supabase.co/storage/v1/object/public/" + SB_BUCKET + "/";

#define PIN_LED D4                           // Active LOW
const unsigned long JEDA_CEK_UPDATE = 60000; // Cek versi baru tiap 60 detik
const int RSSI_MINIMUM = -80;                // Sinyal lebih lemah dari ini: tunda OTA

unsigned long waktuCekTerakhir = 0;
unsigned long waktuKedipTerakhir = 0;

// Mengembalikan isi version.txt dari bucket, atau "" jika gagal
String bacaVersiTerbaru() {
  BearSSL::WiFiClientSecure client;
  // Catatan keamanan: setInsecure() mengenkripsi koneksi tetapi tidak memeriksa sertifikat
  // server. Cukup untuk latihan. Untuk produksi, pakai setTrustAnchors() atau
  // firmware bertanda tangan (lihat Tantangan Lanjutan di materi Unit 4).
  client.setInsecure();

  HTTPClient http;
  String versi = "";

  // Angka millis() di belakang alamat membuat CDN tidak menyajikan salinan lama
  if (http.begin(client, URL_RILIS + "version.txt?t=" + String(millis()))) {
    int kode = http.GET();
    if (kode == HTTP_CODE_OK) {
      versi = http.getString();
      versi.trim();
    } else {
      Serial.printf("Gagal membaca version.txt (kode HTTP: %d)\n", kode);
    }
    http.end();
  }
  return versi;
}

void cekDanPasangUpdate() {
  // Faktor keberhasilan OTA: sinyal lemah berisiko memutus unduhan di tengah jalan
  if (WiFi.RSSI() < RSSI_MINIMUM) {
    Serial.printf("Sinyal lemah (%d dBm). Pengecekan update ditunda.\n", WiFi.RSSI());
    return;
  }

  String versiTerbaru = bacaVersiTerbaru();
  if (versiTerbaru == "") return;

  Serial.printf("Versi terpasang: %s | Versi di bucket: %s\n", FW_VERSION, versiTerbaru.c_str());
  if (versiTerbaru == FW_VERSION) {
    Serial.println("Firmware sudah yang terbaru.");
    return;
  }

  Serial.println("Versi berbeda. Mengunduh firmware.bin ...");
  BearSSL::WiFiClientSecure client;
  client.setInsecure(); // Lihat catatan keamanan pada bacaVersiTerbaru()

  ESPhttpUpdate.setLedPin(PIN_LED, LOW); // LED D4 berkedip selama unduhan

  // Jika berhasil, perangkat restart otomatis dan baris di bawah tidak dijalankan.
  // Jika gagal, firmware lama tetap utuh dan terus berjalan.
  t_httpUpdate_return hasil = ESPhttpUpdate.update(client, URL_RILIS + "firmware.bin?v=" + versiTerbaru);

  if (hasil == HTTP_UPDATE_FAILED) {
    Serial.printf("OTA gagal (%d): %s\n", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, HIGH);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("\nMenghubungkan ke Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.printf("\nTerhubung. IP: %s | Firmware versi %s\n", WiFi.localIP().toString().c_str(), FW_VERSION);

  cekDanPasangUpdate(); // Cek sekali saat perangkat baru menyala
}

void loop() {
  if (millis() - waktuCekTerakhir >= JEDA_CEK_UPDATE) {
    waktuCekTerakhir = millis();
    cekDanPasangUpdate();
  }

  // Logika aplikasi. Pada versi berikutnya, ubah jeda kedip ini
  // (misalnya dari 1000 menjadi 200) sebagai bukti visual bahwa OTA berhasil.
  if (millis() - waktuKedipTerakhir >= 1000) {
    waktuKedipTerakhir = millis();
    digitalWrite(PIN_LED, !digitalRead(PIN_LED));
  }
}
