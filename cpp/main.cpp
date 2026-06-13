main.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Data {
    string tanggal;
    string lokasi;
    string parameter;
    double nilai;
    string satuan;
};

vector<Data> dataset;

string hitungRating(double persen) {
    if (persen <= 40)
        return "Green";
    else if (persen <= 70)
        return "Warning";
    else
        return "Critical";
}

void bacaCSV(string namaFile) {
    ifstream file(namaFile);

    if (!file.is_open()) {
        cout << "Gagal membuka file!" << endl;
        return;
    }

    string line;

    getline(file, line); // header

    while (getline(file, line)) {

        stringstream ss(line);

        Data d;
        string temp;

        getline(ss, d.tanggal, ',');
        getline(ss, d.lokasi, ',');
        getline(ss, d.parameter, ',');
        getline(ss, temp, ',');
        d.nilai = stod(temp);
        getline(ss, d.satuan, ',');

        dataset.push_back(d);
    }

    file.close();
}

void ringkasanData() {

    set<string> gedung;
    set<string> parameter;

    for (auto d : dataset) {
        gedung.insert(d.lokasi);
        parameter.insert(d.parameter);
    }

    cout << "\n=== RINGKASAN DATA ===\n";
    cout << "Jumlah Record : " << dataset.size() << endl;
    cout << "Jumlah Gedung : " << gedung.size() << endl;
    cout << "Jumlah Parameter : " << parameter.size() << endl;
}

void statistikData() {

    cout << "\n=== STATISTIK ===\n";

    set<string> parameterSet;

    for (auto d : dataset)
        parameterSet.insert(d.parameter);

    for (auto p : parameterSet) {

        vector<double> nilai;

        for (auto d : dataset) {
            if (d.parameter == p)
                nilai.push_back(d.nilai);
        }

        double total = 0;

        for (double x : nilai)
            total += x;

        double rata = total / nilai.size();

        double maks = *max_element(nilai.begin(), nilai.end());
        double mins = *min_element(nilai.begin(), nilai.end());

        cout << "\n" << p << endl;
        cout << "Rata-rata : " << fixed << setprecision(2) << rata << endl;
        cout << "Maksimum  : " << maks << endl;
        cout << "Minimum   : " << mins << endl;
    }
}

void analisisKampus() {

    cout << "\n=== ANALISIS KAMPUS ===\n";

    set<string> parameterSet;

    for (auto d : dataset)
        parameterSet.insert(d.parameter);

    for (auto p : parameterSet) {

        map<string, pair<double, int>> dataGedung;

        for (auto d : dataset) {

            if (d.parameter == p) {

                dataGedung[d.lokasi].first += d.nilai;
                dataGedung[d.lokasi].second++;
            }
        }

        string gedungTertinggi;
        double nilaiTertinggi = 0;

        for (auto item : dataGedung) {

            double rata =
                item.second.first /
                item.second.second;

            if (rata > nilaiTertinggi) {

                nilaiTertinggi = rata;
                gedungTertinggi = item.first;
            }
        }

        cout << p << " Tertinggi : "
             << gedungTertinggi
             << " ("
             << fixed
             << setprecision(2)
             << nilaiTertinggi
             << ")"
             << endl;
    }
}

void sustainabilityRating() {

    cout << "\n=== SUSTAINABILITY RATING ===\n";

    map<string, pair<double, int>> energyGedung;

    for (auto d : dataset) {

        if (d.parameter == "Energy") {

            energyGedung[d.lokasi].first += d.nilai;
            energyGedung[d.lokasi].second++;
        }
    }

    map<string, double> rataGedung;

    double maksimum = 0;

    for (auto item : energyGedung) {

        double rata =
            item.second.first /
            item.second.second;

        rataGedung[item.first] = rata;

        if (rata > maksimum)
            maksimum = rata;
    }

    for (auto item : rataGedung) {

        double persen =
            (item.second / maksimum) * 100;

        cout << item.first
             << " - "
             << hitungRating(persen)
             << endl;
    }
}

void simpanLaporan() {

    ofstream file("../output/laporan_sustainability.txt");

    if (!file.is_open()) {

        cout << "Gagal membuat file laporan!" << endl;
        return;
    }

    set<string> gedung;
    set<string> parameter;

    for (auto d : dataset) {

        gedung.insert(d.lokasi);
        parameter.insert(d.parameter);
    }

    file << "LAPORAN SUSTAINABILITY UNESA\n\n";

    file << "Jumlah Record : "
         << dataset.size()
         << "\n";

    file << "Jumlah Gedung : "
         << gedung.size()
         << "\n";

    file << "Jumlah Parameter : "
         << parameter.size()
         << "\n\n";

    for (auto p : parameter) {

        vector<double> nilai;

        for (auto d : dataset) {

            if (d.parameter == p)
                nilai.push_back(d.nilai);
        }

        double total = 0;

        for (double x : nilai)
            total += x;

        double rata = total / nilai.size();

        double maks =
            *max_element(nilai.begin(),
                         nilai.end());

        double mins =
            *min_element(nilai.begin(),
                         nilai.end());

        file << p << endl;
        file << "Rata-rata : "
             << fixed
             << setprecision(2)
             << rata << endl;

        file << "Maksimum : "
             << maks << endl;

        file << "Minimum : "
             << mins << endl << endl;
    }

    file.close();

    cout << "\nLaporan berhasil disimpan!\n";
}

int main() {

    bacaCSV("../dataset/sustainability_data.csv");

    int pilih;

    do {

        cout << "\n===== ANALISIS SUSTAINABILITY UNESA =====\n";
        cout << "1. Ringkasan Dataset\n";
        cout << "2. Statistik Data\n";
        cout << "3. Analisis Kampus\n";
        cout << "4. Sustainability Rating\n";
        cout << "5. Simpan Laporan\n";
        cout << "0. Keluar\n";
        cout << "Pilih Menu : ";

        cin >> pilih;

        switch (pilih) {

        case 1:
            ringkasanData();
            break;

        case 2:
            statistikData();
            break;

        case 3:
            analisisKampus();
            break;

        case 4:
            sustainabilityRating();
            break;

        case 5:
            simpanLaporan();
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 0);

    return 0;
}
```