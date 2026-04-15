// --- Tab Utama: Edgent_ESP8266 ---

// Ganti dengan Kredensial Template Anda dari Blynk Web Console
#define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
#define BLYNK_TEMPLATE_NAME "mySertifikasi"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG

// Mengaktifkan Custom Board untuk KasgarIoT Shield
#define USE_KASGARIOT_SHIELD

#include "BlynkEdgent.h"

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}
