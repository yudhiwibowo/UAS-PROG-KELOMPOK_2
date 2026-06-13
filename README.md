# Sistem Analisis Sustainability UNESA

## Anggota Kelompok

- Muhammad Yudhi Wahyu Wibowo
- Indryana Azaki
- Azam Irfansyah
- Four Rezeki Waruwu

## Deskripsi

Proyek ini merupakan sistem analisis sustainability kampus UNESA yang memanfaatkan data sensor IoT untuk memantau berbagai parameter lingkungan, yaitu konsumsi energi (Energy), penggunaan air (Water), emisi karbon (CO₂), dan produksi sampah (Waste).

Program dikembangkan menggunakan dua bahasa pemrograman, yaitu C++ dan Python, dengan fungsi yang sama untuk melakukan analisis data, menghasilkan statistik, menentukan gedung dengan konsumsi tertinggi, memberikan sustainability rating, serta menyimpan hasil analisis ke dalam file laporan.

## Cara Menjalankan C++

```bash
g++ main.cpp -o main
./main
```

## Cara Menjalankan Python

```bash
python main.py
```

## Ringkasan Hasil Analisi

Berdasarkan analisis terhadap dataset sustainability UNESA:

Jumlah Record: 29.200 data
Jumlah Gedung: 20 gedung
Jumlah Parameter: 4 parameter (Energy, Water, CO₂, dan Waste)
Program berhasil membaca dataset dan melakukan analisis statistik berupa nilai rata-rata, maksimum, dan minimum untuk setiap parameter.
Program berhasil mengidentifikasi gedung dengan rata-rata konsumsi energi tertinggi.
Program berhasil mengidentifikasi gedung dengan rata-rata penggunaan air tertinggi.
Program berhasil mengidentifikasi gedung dengan rata-rata emisi CO₂ tertinggi.
Program berhasil mengidentifikasi gedung dengan rata-rata produksi sampah tertinggi.
Program berhasil mengklasifikasikan Sustainability Rating setiap gedung ke dalam kategori:
Green (0–40%)
Warning (40–70%)
Critical (>70%)
Seluruh hasil analisis dapat disimpan ke dalam file laporan_sustainability.txt.

## Ringkasan Hasil Analisis

Berdasarkan analisis terhadap dataset sustainability UNESA:

* Jumlah Record: **29.200 data**
* Jumlah Gedung: **20 gedung**
* Jumlah Parameter: **4 parameter** (Energy, Water, CO₂, dan Waste)
* Program berhasil membaca dataset dan melakukan analisis statistik berupa nilai rata-rata, maksimum, dan minimum untuk setiap parameter.
* Program berhasil mengidentifikasi gedung dengan rata-rata konsumsi energi tertinggi.
* Program berhasil mengidentifikasi gedung dengan rata-rata penggunaan air tertinggi.
* Program berhasil mengidentifikasi gedung dengan rata-rata emisi CO₂ tertinggi.
* Program berhasil mengidentifikasi gedung dengan rata-rata produksi sampah tertinggi.
* Program berhasil mengklasifikasikan Sustainability Rating setiap gedung ke dalam kategori:

  * Green (0–40%)
  * Warning (40–70%)
  * Critical (>70%)
* Seluruh hasil analisis dapat disimpan ke dalam file `laporan_sustainability.txt`.

## Perbandingan C++ dan Python

| Aspek                    | C++                       | Python                               |
| ------------------------ | ------------------------- | ------------------------------------ |
| Kecepatan Eksekusi       | Lebih cepat               | Lebih lambat                         |
| Kemudahan Penulisan Kode | Sintaks lebih kompleks    | Sintaks lebih sederhana              |
| Jumlah Baris Program     | Lebih banyak              | Lebih sedikit                        |
| Pengolahan CSV           | Memerlukan parsing manual | Mudah dengan library Pandas          |
| Kemudahan Debugging      | Relatif lebih sulit       | Lebih mudah                          |
| Penggunaan Memori        | Lebih efisien             | Lebih besar                          |
| Cocok Untuk              | Sistem berperforma tinggi | Analisis data dan pengembangan cepat |

## Video Presentasi

(Link nanti)
