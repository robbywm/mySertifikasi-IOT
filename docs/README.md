# Pelatihan Perekayasaan Perangkat Internet of Things (IoT)

Modul ini disusun untuk mendampingi pelatihan dan pra-asesmen skema sertifikasi **Perekayasaan Perangkat Internet of Things (IoT)**. Seluruh praktik memakai Wemos D1 R2 (ESP8266), KasgarIoT Shield R1, Arduino IDE, dan platform Blynk IoT. Setiap bab mengikuti satu unit kompetensi SKKNI, sehingga hasil praktik Anda dapat langsung dipakai sebagai bukti kerja saat asesmen.

<figure><img src="https://3210525233-files.gitbook.io/~/files/v0/b/gitbook-x-prod.appspot.com/o/spaces%2FOdmXmHPTecdtQ82RSbYz%2Fuploads%2FP0feWDPCl1es1s0Vo0VX%2F1.%20Pelatihan%20%26%20Sertifikasi%20Perekayasaan%20Perangkat%20IoT.png?alt=media&amp;token=7f785b25-6cc2-469e-b106-3eae472f1940" alt=""><figcaption></figcaption></figure>

## Cara memakai modul ini

Peserta pelatihan biasanya datang dengan bekal yang berbeda-beda, sehingga setiap bab pada modul ini memuat tiga jenis kotak bantuan:

{% hint style="info" %}
**Untuk pemula.** Penjelasan tambahan tentang istilah atau langkah yang sering membingungkan peserta baru. Peserta yang sudah berpengalaman boleh melewatinya.
{% endhint %}

{% hint style="warning" %}
**Perhatian.** Kesalahan yang sering terjadi di kelas dan cara menghindarinya.
{% endhint %}

{% hint style="success" %}
**Tantangan lanjutan.** Tugas tambahan bagi peserta yang selesai lebih cepat. Tantangan ini tidak wajib untuk asesmen, tetapi melatih kebiasaan kerja di industri.
{% endhint %}

Saran jalur belajarnya sebagai berikut.

| Profil peserta | Saran |
| --- | --- |
| Pemula (belum pernah memprogram mikrokontroler) | Kerjakan semua bab secara berurutan, baca setiap kotak **Untuk pemula**, dan salin program apa adanya sebelum mencoba mengubahnya. |
| Menengah (pernah memakai Arduino atau ESP8266) | Bab 1 dan 2 cukup dibaca cepat sambil mengisi lembar kerjanya, lalu fokus pada Bab 3 sampai 8. |
| Mahir (pernah membangun produk IoT) | Fokus pada lembar kerja dan dokumen yang diminta SKKNI, lalu kerjakan seluruh **Tantangan lanjutan**. |

Apa pun profil Anda, lembar kerja pada setiap bab tetap wajib diisi, karena yang dinilai oleh asesor adalah bukti kerja tersebut dan perangkat yang menyala saja belum cukup untuk menunjukkan kompetensi.

## SKKNI yang menjadi acuan

SKKNI (Standar Kompetensi Kerja Nasional Indonesia) adalah rumusan kemampuan kerja yang mencakup pengetahuan, keterampilan, dan sikap kerja untuk suatu pekerjaan. Standar ini ditetapkan oleh Menteri Ketenagakerjaan dan dipakai oleh tiga pihak: lembaga pendidikan dan pelatihan sebagai acuan kurikulum, dunia usaha sebagai acuan rekrutmen dan pengembangan karyawan, serta lembaga sertifikasi profesi (LSP) sebagai acuan uji kompetensi.

Untuk bidang IoT, acuannya adalah **Keputusan Menteri Ketenagakerjaan Republik Indonesia Nomor 300 Tahun 2020** tentang Penetapan SKKNI Kategori Informasi dan Komunikasi Golongan Pokok Telekomunikasi Bidang Internet of Things (IoT). Naskah lengkapnya dapat dibaca di [JDIH Kemnaker](https://jdih.kemnaker.go.id/peraturan/detail/1980/keputusan-menteri-ketenagakerjaan-nomor-300-tahun-2020). Penjelasan umum tentang SKKNI tersedia di artikel [SKKNI Sebagai Standar Kerja di Indonesia](https://indobot.co.id/blog/skkni-sebagai-standar-kerja-di-indonesia/).

### Cara membaca kode unit

Setiap unit kompetensi memiliki kode yang terdiri atas dua belas karakter, dan sebagai contoh kode **J.61IOT01.018.1** dibaca seperti berikut.

| Bagian kode | Arti |
| --- | --- |
| `J` | Kategori lapangan usaha menurut KBLI (Klasifikasi Baku Lapangan Usaha Indonesia). Huruf J berarti Informasi dan Komunikasi. Daftar kodenya dapat dilihat di [OSS](https://oss.go.id/informasi/kbli-berbasis-risiko). |
| `61` | Golongan pokok pada KBLI. Angka 61 berarti Telekomunikasi. |
| `IOT` | Singkatan bidang atau area pekerjaan, ditulis dengan tiga huruf kapital. |
| `01` | Penjabaran area pekerjaan. Angka 00 berarti tidak ada penjabaran. |
| `018` | Nomor urut unit kompetensi di dalam SKKNI tersebut. |
| `1` | Versi penerbitan unit. |

### Isi sebuah unit kompetensi

Setiap unit di dalam SKKNI memuat bagian yang sama, dan yang paling perlu Anda perhatikan adalah elemen kompetensi beserta kriteria unjuk kerja (KUK), karena keduanya akan menjadi daftar periksa asesor.

| Bagian | Isi |
| --- | --- |
| Kode, judul, dan deskripsi unit | Identitas unit dan gambaran singkat pekerjaannya. |
| Elemen kompetensi | Tahapan pekerjaan yang harus dapat dilakukan. |
| Kriteria unjuk kerja (KUK) | Hasil terukur dari setiap tahapan. |
| Batasan variabel | Konteks, peralatan, peraturan, serta norma dan standar yang berlaku. |
| Panduan penilaian | Konteks penilaian, pengetahuan dan keterampilan yang dibutuhkan, sikap kerja, dan aspek kritis. |

Pada awal setiap bab, modul ini menyajikan tabel **Peta kompetensi** yang menghubungkan setiap KUK dengan bagian materi dan bukti kerja yang menjawabnya. Teks elemen dan KUK dikutip apa adanya dari Kepmenaker 300/2020.

## Skema Perekayasaan Perangkat IoT

Skema ini memuat delapan unit kompetensi, yang pada modul ini disusun mengikuti urutan pekerjaan di lapangan, mulai dari memasang perangkat sampai menguji aplikasinya.

| Bab | Kode unit | Judul unit | Hasil akhir bab |
| --- | --- | --- | --- |
| 1 | J.61IOT01.018.1 | Melakukan Instalasi Perangkat IoT (Device) Sesuai Desain | Perangkat terpasang, rencana dan laporan instalasi |
| 2 | J.61IOT01.004.1 | Mengintegrasikan Perangkat Keras dan Perangkat Lunak (Firmware) untuk Device IoT | Seluruh sensor dan aktuator teruji, laporan pengujian komponen |
| 3 | J.61IOT01.008.1 | Membuat Program Visual Antarmuka pada Perangkat Berbasis Web yang Terintegrasi dengan Mikrokontroler | Dashboard Blynk terhubung dengan perangkat, laporan uji coba |
| 4 | J.61IOT01.019.1 | Melakukan Instalasi Firmware pada Perangkat (Device) Secara Over The Air (OTA) | Firmware terpasang lewat OTA, rancangan dan SOP OTA |
| 5 | J.61IOT01.026.1 | Menerapkan Perimeter Keamanan pada Perangkat IoT | WiFi provisioning berjalan, analisis ancaman dan rencana pemulihan |
| 6 | J.61IOT01.041.1 | Mengaplikasikan Patch Keamanan pada Perangkat IoT | Patch terkirim lewat OTA, dokumentasi patch dan fallback |
| 7 | J.61IOT01.005.1 | Menguji Coba Device IoT | Form A: Quality Control perangkat keras |
| 8 | J.61IOT01.010.1 | Menguji Coba Aplikasi IoT | Form B: uji UI, usability, dan UX |

## Apa itu Internet of Things

Internet of Things (IoT) adalah sistem yang menghubungkan perangkat fisik ke internet sehingga kondisinya dapat dipantau (*monitoring*) dan dikendalikan (*controlling*) dari jarak jauh. Sistem tersebut tersusun atas perangkat keras, firmware, jaringan, platform cloud, dan aplikasi, sehingga pengerjaannya umumnya melibatkan lebih dari satu engineer.

Skema Perekayasaan Perangkat IoT berfokus pada sisi perangkat (*device*): memasang, memprogram, menghubungkan ke platform, memperbarui firmware, mengamankan, dan mengujinya.

## Program praktik

Seluruh program pada modul ini tersedia di repository [mySertifikasi-IOT](https://github.com/robbywm/mySertifikasi-IOT). Nama folder program diawali nomor urut, dan nomor itulah yang dirujuk pada setiap langkah kerja.

| Bab | Program |
| --- | --- |
| 2 | `1.Pengujian_LED` sampai `7.Pengujian_RGB` |
| 3 | `8.Uji_Konektivitas_Awal` sampai `14.Pemantauan_Tekanan_Udara` |
| 4 | `15.Reset_EEPROM`, `16.Injeksi_Awal_OTA`, `17.Update_OTA_Local`, `22.OTA_Supabase_Storage` |
| 5 | `18.Blynk_Edgent` |
| 6 | `19.PraPatching_OTA`, `20.Patching_OTA` |
| 7 | Program 1 sampai 7 dipakai ulang untuk pengujian |
| 8 | `21.Program_Integrasi_OTA` |

## Bukti kerja yang dikumpulkan

Simpan semua lembar kerja dan tangkapan layar ke dalam satu dokumen portofolio, karena dokumen itulah yang akan Anda bawa ke asesmen.

| Bab | Bukti kerja |
| --- | --- |
| 1 | Lembar Rencana Instalasi, Laporan Instalasi dan Troubleshooting |
| 2 | Lembar Identifikasi Komponen, tangkapan layar tujuh pengujian, Laporan Pengujian Komponen |
| 3 | Spesifikasi dashboard, tangkapan layar dashboard, Laporan Uji Coba Program Visual |
| 4 | Dokumen Rancangan dan SOP OTA, bukti OTA lokal dan OTA Supabase Storage |
| 5 | Lembar Analisis Ancaman, Rencana Pencegahan dan Pemulihan |
| 6 | Lembar Dokumentasi Patch, bukti versi firmware sebelum dan sesudah patch |
| 7 | Form A: Hardware QC |
| 8 | Form B: Usability dan UI/UX Testing |

## Manfaat sertifikasi

**Bagi industri**

* Memberi dasar untuk meyakinkan klien bahwa pekerjaan ditangani oleh tenaga yang kompeten.
* Mempermudah rekrutmen dan pengembangan karyawan berbasis kompetensi.
* Menjadi acuan jenjang karier dan regenerasi tenaga kerja.

**Bagi pekerja**

* Menjadi bukti tertulis bahwa Anda kompeten pada bidang yang disertifikasi.
* Membantu merencanakan karier dan mengukur capaian belajar, baik di lembaga formal maupun secara mandiri.
* Memenuhi persyaratan regulasi pada pekerjaan yang mewajibkan sertifikat kompetensi.
* Membuka pengakuan kompetensi lintas sektor dan lintas negara.

[Indobot Academy](https://indobot.co.id/daftar) menyelenggarakan pelatihan IoT yang mengacu pada SKKNI ini.
