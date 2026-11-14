# mySertifikasi-IOT

Program praktik dan materi pelatihan skema sertifikasi **Perekayasaan Perangkat Internet of Things (IoT)**, mengacu pada SKKNI Kepmenaker Nomor 300 Tahun 2020.

Perangkat: Wemos D1 R2 (ESP8266) + KasgarIoT Shield R1. Board di Arduino IDE: **LOLIN(WEMOS) D1 R2 & mini**.

## Isi repository

| Folder | Isi |
| --- | --- |
| `docs/` | Materi pelatihan dalam format GitBook (lihat `docs/SUMMARY.md`) |
| `1.` sampai `22.` | Program Arduino, satu folder per program |
| `AUDIT-MATERI.md` | Laporan audit materi dan daftar perubahan |

## Program per unit kompetensi

| Bab | Unit | Program |
| --- | --- | --- |
| 1 | J.61IOT01.018.1 Instalasi perangkat | `1.Pengujian_LED` (dipakai untuk verifikasi) |
| 2 | J.61IOT01.004.1 Integrasi hardware dan firmware | `1.Pengujian_LED`, `2.Pengujian_Switch`, `3.Pengujian_Switch_LED`, `4.Pengujian_DHT22`, `5.Pengujian_Potensiometer`, `6.Pengujian_BMP280`, `7.Pengujian_RGB` |
| 3 | J.61IOT01.008.1 Program visual antarmuka | `8.Uji_Konektivitas_Awal`, `9.Analisis_Jaringan`, `10.Pengendalian_Output_Digital`, `11.Pemantauan_Input_Digital`, `12.Pemantauan_Input_Analog`, `13.Pemantauan_Suhu_Kelembapan`, `14.Pemantauan_Tekanan_Udara` |
| 4 | J.61IOT01.019.1 Instalasi firmware OTA | `15.Reset_EEPROM`, `16.Injeksi_Awal_OTA`, `17.Update_OTA_Local`, `22.OTA_Supabase_Storage` |
| 5 | J.61IOT01.026.1 Perimeter keamanan | `18.Blynk_Edgent` |
| 6 | J.61IOT01.041.1 Patch keamanan | `19.PraPatching_OTA`, `20.Patching_OTA` |
| 7 | J.61IOT01.005.1 Uji coba device | Program 1 sampai 7 |
| 8 | J.61IOT01.010.1 Uji coba aplikasi | `21.Program_Integrasi_OTA` |

## Library yang dibutuhkan

Instal melalui **Sketch > Include Library > Manage Libraries** di Arduino IDE:

* Blynk
* DHT sensor library (Adafruit), beserta Adafruit Unified Sensor
* Adafruit BMP280 Library, beserta dependensinya

Board package: **esp8266 by ESP8266 Community**, dengan alamat Boards Manager `https://arduino.esp8266.com/stable/package_esp8266com_index.json`.

## Pemetaan pin KasgarIoT Shield R1

| Komponen | Pin | GPIO | Logika |
| --- | --- | --- | --- |
| LED status | D4 | 2 | Active LOW |
| DHT22 | D5 | 14 | |
| LED RGB biru | D6 | 12 | Active HIGH |
| LED RGB merah | D7 | 13 | Active HIGH |
| LED RGB hijau | D8 | 15 | Active HIGH |
| Tombol USER | D3 | 0 | Active LOW |
| Potensiometer | A0 | | |
| BMP280 | D1 (SCL), D2 (SDA) | 5, 4 | I2C 0x76 |

## Sebelum meng-upload

Ganti nilai contoh di dalam program (`TMPLxxxxxx`, `NAMA_WIFI`, `SANDI_WIFI`, `GANTI_SANDI_OTA`, `USERNAME_GITHUB`, dan sejenisnya) dengan milik Anda. Jangan meng-commit program yang masih memuat Auth Token atau password Wi-Fi asli.
