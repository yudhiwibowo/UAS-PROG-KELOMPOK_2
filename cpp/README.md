# Implementasi C++

## Deskripsi

Program C++ ini digunakan untuk menganalisis data sustainability kampus UNESA berdasarkan dataset yang tersimpan dalam file CSV. Program menyediakan menu interaktif untuk menampilkan ringkasan data, statistik parameter, analisis gedung, sustainability rating, dan pembuatan laporan hasil analisis.

## File

* `main.cpp` : Program utama analisis sustainability.

## Fitur

1. Membaca dataset dari file CSV.
2. Menampilkan ringkasan dataset.
3. Menghitung statistik setiap parameter.
4. Menentukan gedung dengan nilai rata-rata tertinggi pada setiap parameter.
5. Memberikan Sustainability Rating (Green, Warning, Critical).
6. Menyimpan hasil analisis ke file laporan.

## Cara Kompilasi

```bash
g++ main.cpp -o main
```

## Cara Menjalankan

Windows:

```bash
main.exe
```

Linux/macOS:

```bash
./main
```

## Struktur Data yang Digunakan

* Struct
* Vector
* Set
* Map
* File Handling
* String Stream

## Input

Program membaca data dari:

```text
../dataset/sustainability_data.csv
```

## Output

Program menghasilkan laporan:

```text
../output/laporan_sustainability.txt
```
