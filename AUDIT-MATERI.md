# Laporan Audit Materi Pelatihan Perekayasaan Perangkat IoT

Tanggal audit: 11 November 2026

Objek audit: [kasgariot.gitbook.io/mysertifikasi-iot](https://kasgariot.gitbook.io/mysertifikasi-iot) (9 halaman) dan 21 program di repository ini.

Acuan: Keputusan Menteri Ketenagakerjaan RI Nomor 300 Tahun 2020 tentang Penetapan SKKNI Kategori Informasi dan Komunikasi Golongan Pokok Telekomunikasi Bidang Internet of Things (IoT), diunduh dari [JDIH Kemnaker](https://jdih.kemnaker.go.id/peraturan/detail/1980/keputusan-menteri-ketenagakerjaan-nomor-300-tahun-2020). Elemen kompetensi dan KUK kedelapan unit dibaca langsung dari naskah tersebut.

Hasil: materi ditulis ulang ke folder `docs/`, 13 berkas program diperbaiki, dan 1 program baru ditambahkan.

## 1. Ringkasan temuan

| Kelompok | Jumlah temuan | Tingkat |
| --- | --- | --- |
| Kesenjangan terhadap KUK SKKNI | Ada di kedelapan unit (65 KUK), terutama KUK yang meminta dokumen | Tinggi |
| Kesalahan fakta teknis dan ketidakkonsistenan | 23, dirinci pada Bagian 3 | Tinggi sampai sedang |
| Bahasa | Lihat Bagian 4 | Sedang |
| Program | 9 perbaikan, 1 tambahan | Sedang |

Temuan terpenting: materi lama hampir seluruhnya berisi praktik, sedangkan SKKNI banyak meminta dokumen (rencana, rancangan, SOP, analisis, laporan). Peserta yang hanya mengikuti materi lama dapat mendemonstrasikan perangkat tetapi tidak memiliki bukti tertulis untuk sebagian besar KUK.

## 2. Kesenjangan terhadap SKKNI dan penambahannya

| Bab | Unit | Yang diminta KUK tetapi tidak ada di materi lama | Yang ditambahkan |
| --- | --- | --- | --- |
| 1 | J.61IOT01.018.1 | Rencana instalasi dan dokumentasinya (1.2, 1.3), verifikasi terhadap hasil uji lab (1.1, 3.1), troubleshooting dan dokumentasinya (2.1, 2.2), dokumentasi hasil dan ketidaksesuaian (1.5, 3.2). Materi lama hanya memuat teori dan instalasi software | Lembar Rencana Instalasi, langkah pemasangan fisik dengan SOP ESD, Lembar Verifikasi 9 butir termasuk pengukuran multimeter, tabel troubleshooting 7 gejala, Laporan Instalasi |
| 2 | J.61IOT01.004.1 | Identifikasi komponen, datasheet, dan library (1.1, 1.2), identifikasi komponen yang tidak sesuai datasheet (2.4), laporan komponen bermasalah dan diskusi (3.1, 3.2) | Tabel protokol, Lembar Identifikasi Komponen dengan acuan datasheet, hasil yang diharapkan di tiap pengujian, Laporan Pengujian Komponen, tabel bantu diagnosis |
| 3 | J.61IOT01.008.1 | Penentuan spesifikasi berdasarkan kebutuhan (1.1, 2.1), pengumpulan hasil uji, evaluasi, dan laporan (3.1 sampai 3.3) | Tabel spesifikasi dashboard, tabel alur data, tabel RSSI, hasil yang diharapkan di tiap praktik, Laporan Uji Coba Program Visual dengan evaluasi |
| 4 | J.61IOT01.019.1 | Rancangan tertulis sistem manajemen firmware (1.1), faktor keberhasilan OTA (1.2), SOP (1.3), dokumentasi penggunaan (2.2), pemastian jaringan sesuai SLA (3.2) | Perbandingan arsitektur OTA, tabel faktor keberhasilan, Dokumen Rancangan OTA, SOP OTA 10 langkah, praktik OTA dari Supabase Storage, catatan rilis, lembar pemeriksaan SLA |
| 5 | J.61IOT01.026.1 | Identifikasi ancaman dengan model risiko (1.1), analisis aspek teknis dan nonteknis (1.2, 1.3), strategi pemulihan (2.1), laporan analisis (3.1), rencana pencegahan dan pemulihan sesuai SLA (3.2). Materi lama hanya memuat praktik provisioning | Model risiko kemungkinan × dampak, Lembar Analisis Ancaman, pencatatan waktu pemulihan pada simulasi, Rencana Pencegahan dan Pemulihan |
| 6 | J.61IOT01.041.1 | Identifikasi empat lapisan keamanan (1.1), penempatan patch (1.2), alur uji dan fallback (1.3), parameter keberhasilan (2.2), fallback (2.3), tata cara dan dokumentasi (3.1, 3.2) | Tabel lapisan keamanan, tabel penempatan patch, alur penerapan bertahap, penjelasan fallback pada ESP8266, tabel parameter keberhasilan, latihan fallback versi 0.1.2, Lembar Dokumentasi Patch |
| 7 | J.61IOT01.005.1 | Identifikasi jenis jaringan dan spesifikasi sistem (1.1), alur kerja dan panduan uji (1.3). Aspek kritis "ketepatan perhitungan waktu uji coba" tidak tersentuh | Lembar Spesifikasi Sistem, tabel alur uji per program, pencatatan waktu uji, Form A ditambah butir pemeriksaan visual dan aplikasi tertanam |
| 8 | J.61IOT01.010.1 | Identifikasi spesifikasi, jenis aplikasi, komponen, dan alur kerja (1.1 sampai 1.3). Uji UI, usability test, dan UX test (2.1 sampai 2.3) tercampur menjadi satu | Lembar Persiapan Uji, pemisahan tegas tiga jenis uji, UX test berbasis tugas dengan orang lain dan stopwatch, Form B disusun ulang |

Tambahan yang berlaku untuk semua bab: tabel Peta Kompetensi (KUK, bagian materi, bukti kerja), kotak **Untuk pemula**, **Perhatian**, dan **Tantangan lanjutan** untuk peserta dengan tingkat berbeda, serta Cek Pemahaman untuk persiapan asesmen lisan dan tertulis. Halaman Glosarium ditambahkan sebagai lampiran.

## 3. Kesalahan fakta dan ketidakkonsistenan

| No | Lokasi | Materi lama | Perbaikan | Dasar |
| --- | --- | --- | --- | --- |
| 1 | Bab 2, Pengujian 4 | DHT22 "terhubung dengan Pin D6" | D5 | Kode pada halaman yang sama dan daftar pin shield |
| 2 | Bab 5 dan 6 | Indikator Edgent disebut "LED RGB Biru (Pin D7)" | LED RGB biru di D6 | `Settings.h` memakai GPIO12, yaitu D6. D7 adalah merah |
| 3 | Bab 5 | Setelah online, LED "mati secara statis" | LED terang dan redup bergantian secara perlahan | `Indicator.h`: `MODE_RUNNING` memakai `waveLED` |
| 4 | Bab 5 | Kredensial "dienkripsi dan disimpan dengan aman" | Disimpan di EEPROM tanpa enkripsi, pengamanan fisik tetap perlu | `ConfigStore.h` menulis struct apa adanya ke EEPROM |
| 5 | Bab 2, Pengujian 2 | Tombol "terhubung ke Ground melalui resistor pull-up internal" | Tombol menghubungkan pin ke GND saat ditekan, pull-up menahan nilai 1 saat dilepas | Cara kerja `INPUT_PULLUP` |
| 6 | Bab 2, Pengujian 7 | Active HIGH "karena mem-fungsikan pin D8 sebagai pull-down natural" | GPIO15 harus LOW saat boot, sehingga LED di pin itu padam pada LOW | Mode boot ESP8266 |
| 7 | Bab 3, Praktik 5 | DHT22 memakai "pustaka One-Wire" | Protokol satu kabel khusus DHT, berbeda dari 1-Wire | Datasheet AM2302 |
| 8 | Bab 4 | Menghapus EEPROM menghapus jejak jaringan "secara tuntas", dan `WiFi.begin()` dianggap menyimpan kredensial ke flash | Kredensial Wi-Fi SDK berada di luar EEPROM dan dihapus terpisah. Pada core 3.1.2, `WiFi.persistent()` bernilai `false` secara bawaan, sehingga `WiFi.begin(ssid, password)` tidak menyimpan apa pun. Penyimpanan baru terjadi bila memanggil `WiFi.persistent(true)` | Diuji pada Wemos D1 R2, core 3.1.2 |
| 9 | Bab 4 | ArduinoOTA tanpa password, padahal dua bab berikutnya membahas keamanan | Password OTA ditambahkan | Program 16 dan 17 |
| 10 | Bab 6 | HTTPS "menjamin" firmware tidak disisipi malware. Klaim SOC 2, hash di sisi klien, blokir IP ditulis sebagai fakta | Dibatasi pada yang terlihat di kode: TLS port 443 dan pemeriksaan MD5. Sisanya disebut "menurut dokumentasinya" | `OTA.h`, `Settings.h` |
| 11 | Bab 6 | Kalibrasi sensor disebut patch keamanan tanpa penjelasan | Dijelaskan sebagai simulasi, ditambah contoh patch keamanan yang sesungguhnya | Definisi patch keamanan |
| 12 | Bab 7 | Deskripsi unit disalin dari unit Menguji Coba Aplikasi IoT | Diganti dengan deskripsi unit J.61IOT01.005.1 | Kepmenaker 300/2020 |
| 13 | Bab 1 | RAM ditulis "64Kb" dan "96Kb". Tegangan logika 3,3 V tidak disebut | KB, ditambah baris tegangan logika dan peringatannya | Spesifikasi ESP8266 |
| 14 | Halaman muka | SKKNI IoT tidak diberi nomor. Skema tertulis "loT" (huruf L kecil) | Kepmenaker 300/2020 dengan tautan JDIH, ejaan IoT | JDIH Kemnaker |
| 15 | Bab 3 dan 8 lawan Bab 5 dan 6 | Nama template "MySertifikasi" dan "mySertifikasi" dipakai bergantian | Seragam `MySertifikasi` di materi dan program | Konsistensi |
| 16 | Bab 6 | Komentar dan pesan Serial menyebut "Versi 1.0" dan "1.1", sedangkan versi firmware 0.1.0 dan 0.1.1 | Disamakan dengan nomor versi | Program 19 dan 20 |
| 17 | Bab 8 | Ambang latency: ">500ms" di teori, "0-100, 100-300, >400" di langkah kerja | Satu tabel: <100, 100 sampai 300, >300 ms | Konsistensi |
| 18 | Bab 6 | Penomoran bagian melompat (1.2 ke 1.4, lalu Bagian 3 tanpa Bagian 2) | Dinomori ulang | |
| 19 | Bab 7 | Merujuk rubrik "di Bagian 6" yang tidak ada | Diperbaiki ke Bagian 5 | |
| 20 | Bab 1 | Tautan unduhan dibungkus `google.com/url?...`. Alamat board package memakai `http` | Tautan langsung, `https` | |
| 21 | Bab 6 | Berkas `.bin` Arduino IDE 2 disebut ada di subfolder `bin` | Subfolder `build` | Perlu dicek, lihat Bagian 7 |
| 22 | Bab 5 | Alur provisioning tanpa menyebut Bluetooth dan layar yang muncul | Wi-Fi dan Bluetooth **ponsel** dinyalakan, lalu **+ > Find Nearby > Find Devices**. ESP8266 sendiri tidak memiliki Bluetooth, tetapi aplikasi Blynk memerlukannya di ponsel untuk menemukan perangkat | Diuji pada ponsel Android dan perangkat |
| 23 | Semua bab | Baud rate 9600 dan 115200 berganti tanpa penjelasan | Baud rate disebut di setiap langkah | |

## 4. Audit bahasa

Register sasaran: bahan ajar. Contoh tulisan penulis tidak tersedia, sehingga kalibrasi suara tidak dilakukan dan dipakai suara netral untuk modul praktikum.

### 4.1. Pola yang diperbaiki

| Pola pada materi lama | Contoh | Perbaikan |
| --- | --- | --- |
| Istilah teknis dipaksa diterjemahkan | "pangkalan perangkat lunak publik", "lucutan listrik statis", "komputasi awan", "telepon pintar", "peramban web" | App Store dan Google Play (dihapus dari kalimat), ESD, cloud, smartphone, browser |
| Istilah Indonesia dan Inggris berpasangan terus-menerus | "purwarupa (prototyping), penerapan (deployment)" | Satu istilah saja, padanan hanya pada kemunculan pertama atau di Glosarium |
| Kosakata bergengsi dan intensifier | "komprehensif", "krusial", "sangat vital", "mutlak digunakan", "ujung tombak", "framework canggih" | Dihapus atau diganti pernyataan konkret |
| Kalimat terjemahan dari teks pemasaran | Paragraf Blynk: "pada berbagai tingkatan skala; mulai dari proyek personal hingga jutaan produk komersial massal" | Ditulis ulang dari gagasannya |
| Em dash | 2 buah pada paragraf White Label | 0 |
| Verba ringan | "melakukan penghapusan", "melaksanakan kendali", "melakukan pengamatan" | menghapus, mengendalikan, mengamati |
| Judul langkah berisi kalimat panjang | Seluruh judul `{% step %}` | Judul pendek, penjelasan di badan langkah |
| Salah ketik dan bentuk tidak baku | "Deksripsi", "rekruitmen", "karir", "efisensi", "merespon", "linier", "otentikasi", "indik ator", "dipasar" | Deskripsi, rekrutmen, karier, efisiensi, merespons, linear (dihindari), autentikasi, indikator, di pasar |
| Huruf kapital untuk penekanan | "JANGAN KLIK UPLOAD!", "Langkah Sangat Krusial" | Huruf tebal seperlunya |

Judul unit, deskripsi unit, elemen kompetensi, dan KUK **tidak disunting**, karena merupakan kutipan peraturan. Hanya salah susun akibat ekstraksi PDF yang dirapikan.

### 4.2. Keputusan istilah

Keputusan berikut adalah wewenang penulis. Silakan diubah bila tidak sesuai, lalu terapkan ke seluruh bab sekaligus.

| Dipakai | Menggantikan | Alasan |
| --- | --- | --- |
| library | pustaka | Sesuai nama menu Arduino IDE. "Pustaka" hanya muncul di kutipan KUK |
| upload, meng-upload | unggah | Sesuai tombol Arduino IDE |
| compile | kompilasi | Sesuai istilah Arduino IDE |
| dashboard, widget, datastream, template, virtual pin | antarmuka web, instrumen, saluran data, cetak biru, pin virtual | Sesuai nama menu Blynk |
| firmware, patch, provisioning, fallback, troubleshooting | perangkat lunak tertanam, tambalan, dan lain-lain | Dipakai juga oleh SKKNI |
| password | kata sandi, sandi | Sesuai tampilan router dan aplikasi |
| browser, smartphone, cloud, real-time | peramban, telepon pintar, komputasi awan, waktu nyata | Lebih lazim di lapangan |
| perangkat | alat, device (di prosa) | "Device" hanya untuk entitas di Blynk |
| short circuit | korsleting | Seragam dengan istilah teknis lain |
| Tetap bahasa Indonesia: perangkat keras (di kutipan), suhu, kelembapan, tekanan udara, catu daya, jaringan, pengujian, laporan, pemulihan, ancaman | | Istilah umum yang sudah mapan |

### 4.3. Metrik

Diukur dengan `metrik.py` (preset ajar) pada paragraf naratif, di luar kode, tabel, dan langkah kerja.

| Metrik | Lama | Baru | Sasaran |
| --- | --- | --- | --- |
| Rerata panjang kalimat | 18,1 | 15,9 | 16 sampai 21 |
| Simpangan baku | 8,4 | 6,5 | minimal 6,4 |
| Kalimat 28 kata ke atas | 9,2 % | 4,0 % | maksimal 20 % |
| Verba ringan per 100 kata | 0,16 | 0,00 | maksimal 0,4 |
| Enumerasi per 1.000 kata | 0,63 | 0,25 | maksimal 1 |
| "merupakan" per 1.000 kata | 1,90 | 0,00 | maksimal 6,1 |
| Em dash dan en dash | 2 | 0 | 0 |
| Penyangkalan antisipatif | 0 | 0 | 0 |
| Kepadatan kata pemadat | 101,8 | 85,2 | 73 sampai 139 |

Catatan jujur: rerata panjang kalimat versi baru berada sedikit di bawah sasaran (15,9 dari 16). Versi baru memang memuat lebih banyak kalimat perintah pendek, dan satu putaran penyambungan kalimat sudah dilakukan pada paragraf teori (61 suntingan). Metrik hanya menunjukkan ritme. Naskah ini tetap perlu dibaca dan disunting oleh penulis sebelum diterbitkan, terutama paragraf teori di Bab 3, 5, dan 6.

## 5. Perubahan program

Sepuluh program yang diubah atau ditambahkan sudah di-compile untuk board `esp8266:esp8266:d1_mini` (core 3.1.2) tanpa error, lalu sebagian besar diuji pada Wemos D1 R2 dan KasgarIoT Shield R1 (ringkasan pada Bagian 7).

| Program | Perubahan | Alasan |
| --- | --- | --- |
| `6.Pengujian_BMP280` | Mencoba alamat 0x76 lalu 0x77 | Alamat bergantung pada modul |
| `14.Pemantauan_Tekanan_Udara` | Flag `bmpSiap`, data tidak dikirim bila sensor tidak terdeteksi | Sebelumnya tetap mengirim nilai tak valid ke dashboard |
| `15.Reset_EEPROM` | Tambah `ESP.eraseConfig()`, komentar tentang `WiFi.persistent(true)` | Kredensial Wi-Fi SDK berada di luar EEPROM |
| `16.Injeksi_Awal_OTA` | Tambah `ArduinoOTA.setPassword()`, cetak IP dan RSSI | OTA tanpa autentikasi, data untuk lembar SLA |
| `17.Update_OTA_Local` | Password OTA, kedip memakai `millis()`, komentar sisa "[Bagian atas ... tetap sama]" dihapus | `delay()` 1 detik per putaran menghambat `ArduinoOTA.handle()` |
| `18` sampai `21` (`.ino`) | `BLYNK_TEMPLATE_NAME` seragam `MySertifikasi` | Lihat temuan 15 |
| `18` sampai `21` (`Settings.h`) | Komentar pin: GPIO0 = D3, GPIO12 = D6 biru | Sumber kekeliruan D6 dan D7 di materi |
| `19.PraPatching_OTA`, `20.Patching_OTA` | Komentar dan pesan Serial memakai 0.1.0 dan 0.1.1 | Lihat temuan 16 |
| `21.Program_Integrasi_OTA` | Flag `bmpSiap`, alamat 0x76 atau 0x77 | Sama seperti program 14 |
| `22.OTA_Supabase_Storage` (baru) | OTA model pull dari bucket publik Supabase Storage dengan `ESP8266httpUpdate` | Permintaan materi OTA di luar Blynk |

Program 1 sampai 5, 7 sampai 13 tidak diubah.

### Catatan tentang program 22

* Koneksi memakai `setInsecure()`: terenkripsi, tetapi sertifikat server tidak diperiksa. Pilihan ini disengaja agar program muat dan mudah dipahami di kelas, ditandai dengan komentar di kode, dan dijadikan Tantangan Lanjutan di Bab 4.
* Bucket harus public, sehingga `firmware.bin` yang memuat SSID dan password ikut terbuka. Materi memberi peringatan dan menyarankan hotspot sementara. Cara tanpa kredensial di `.bin` (Tantangan Lanjutan di Bab 4) sudah diuji: firmware USB memanggil `WiFi.persistent(true)`, firmware rilis memanggil `WiFi.begin()` tanpa argumen. Tanpa `WiFi.persistent(true)`, perangkat tidak tersambung setelah OTA.
* `version.txt` dipakai sebagai penanda versi. Program menambahkan `?t=` di belakang alamatnya agar CDN tidak menyajikan salinan lama.

## 6. Cara menerapkan ke GitBook

Folder `docs/` memakai format GitBook: `README.md`, `SUMMARY.md`, blok `{% hint %}` dan `{% stepper %}`, dan `.gitbook.yaml` di akar repository yang menunjuk ke `docs/`. Nama berkas disamakan dengan alamat halaman yang sekarang, sehingga tautan lama tetap berlaku. Ke-52 gambar memakai URL yang sama dengan halaman yang sekarang.

**Cara A, Git Sync (disarankan).**

1. Commit dan push perubahan ini ke GitHub.
2. Di GitBook, buat **space baru** untuk uji coba, lalu buka **Configure > Git Sync > GitHub**.
3. Pilih repository `mySertifikasi-IOT` dan branch-nya, dengan arah sinkronisasi awal **GitHub ke GitBook**.
4. Periksa hasilnya. Setelah sesuai, lakukan hal yang sama pada space utama, atau pindahkan alamat situs ke space baru.

Jangan langsung menyinkronkan ke space utama. Sinkronisasi arah GitHub ke GitBook menimpa isi space, dan gambar pada materi ini tersimpan di space yang sekarang.

**Cara B, impor manual.** Pada space GitBook, pilih **Import** lalu unggah berkas `.md` dari folder `docs/` satu per satu, atau salin isi tiap berkas ke halaman yang bersesuaian.

## 7. Hasil uji pada perangkat dan yang belum diverifikasi

Perangkat: Wemos D1 R2 (CH340) dengan KasgarIoT Shield R1, ponsel Android lewat USB debugging, konsol Blynk lewat browser. Jaringan Wi-Fi 2,4 GHz.

**Sudah diuji**

| Butir | Hasil |
| --- | --- |
| Program 1 sampai 7 | Berjalan. DHT22 terbaca 28,4 °C dan 83 %, BMP280 928 hPa, selisih suhu DHT22 dan BMP280 sekitar 1,2 °C |
| Program 8 sampai 14 (Blynk) | Online, ping 12 sampai 52 ms. Kendali dua arah pada program 10 terbukti |
| Program 15 | Konfigurasi terhapus |
| Program 16 dan 17 | OTA lokal berhasil dalam sekitar 23 detik. Password salah ditolak |
| Program 22 (Supabase Storage) | OTA 1.0.0 ke 1.0.1 berhasil dalam kurang dari dua menit sejak `version.txt` diunggah. Firmware di bucket tidak memuat password Wi-Fi: firmware USB memakai `WiFi.persistent(true)`, firmware bucket memakai `WiFi.begin()`. Uji mundur versi berhasil: 1.0.1 kembali ke 1.0.0 dalam kurang dari dua menit setelah berkas lama dihapus dan berkas 1.0.0 diunggah. Dashboard Supabase tidak menimpa berkas bernama sama dan membuat `firmware (1).bin`, sehingga berkas lama harus dihapus dulu |
| Program 22 (versi lama, GitHub Releases) | OTA 1.0.0 ke 1.0.1 dan uji mundur versi berhasil. Program ini kemudian diganti ke Supabase Storage |
| Program 18 | Provisioning lewat aplikasi Blynk berhasil, status `RUNNING`, ping 12 ms |
| Program 19 dan 20 | Versi 0.1.0 berjalan. Patch 0.1.1 terkirim lewat Blynk.Air, status Finished, serial menampilkan `Versi 0.1.1 (Patch Terkalibrasi)` |
| Program 21 | Firmware 0.2.0 terkirim lewat Blynk.Air, perangkat `RUNNING`, data sensor terkirim |

**Temuan dari uji**

* `WiFi.persistent()` bernilai `false` pada core 3.1.2 (temuan 8).
* Alur provisioning di aplikasi Blynk memerlukan Bluetooth ponsel (temuan 22).
* Pada konsol Blynk paket Free, tombol **New Shipping** sempat membuka jendela "All Plans" selagi dua shipment lama masih tercatat. Setelah keduanya dihapus, New Shipping dapat dipakai dan dua shipment baru berhasil. Penyebabnya belum dipastikan, jadi catat ini bila peserta menemui hal serupa.
* Serial Monitor menampilkan karakter acak sesaat setelah reset karena bootloader ESP8266 memakai 74880 baud. Ini wajar.

**Belum diverifikasi**

| Butir | Keterangan |
| --- | --- |
| Reset konfigurasi tombol D3 10 detik | Perlu dilakukan langsung oleh penguji |
| Widget Chart pada template | Tampil "No data" saat dicek, kemungkinan belum terikat ke V0 dan V1 |
| Alamat BMP280 | Belum dicatat apakah modul memakai 0x76 atau 0x77 |
| Waktu pemulihan setelah Blynk.Air | Waktu dari Start Shipping sampai online kembali belum terukur akurat |
| Lokasi `.bin` di Arduino IDE 2 | Ditulis subfolder `build`, perlu dicocokkan dengan versi IDE yang dipakai di kelas |
| Batas paket gratis Blynk | Berubah dari waktu ke waktu. Periksa sebelum kelas |
| Skema LSP | Daftar 8 unit diambil dari materi lama. Cocokkan dengan dokumen skema LSP penyelenggara |
| Gambar | URL gambar dipertahankan, tetapi gambar yang memuat teks keliru (misalnya label D7 untuk LED biru) tidak dapat diperiksa dari sini |
| Tampilan di GitBook | Draf ada di change request #36 dan belum digabung. Blok `{% stepper %}` dan tabel formulir perlu dilihat sekali |
