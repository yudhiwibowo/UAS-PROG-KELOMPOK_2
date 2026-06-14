#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

struct Data {
    string tanggal;
    string lokasi;
    string parameter;
    double nilai;
    string satuan;
};

vector<Data> df;

string hitungRating(double persen) {
    if (persen <= 40)
        return "Green";
    else if (persen <= 70)
        return "Warning";
    else
        return "Critical";
}

bool bacaCSV(string fileData) {

    ifstream file(fileData);

    if (!file.is_open()) {
        cout << "Gagal membuka file: "
             << fileData << endl;
        return false;
    }

    string line;

    getline(file, line);

    while (getline(file, line)) {

        stringstream ss(line);

        Data d;
        string temp;

        getline(ss, d.tanggal, ',');
        getline(ss, d.lokasi, ',');
        getline(ss, d.parameter, ',');
        getline(ss, temp, ',');

        try {
            d.nilai = stod(temp);
        }
        catch (...) {
            continue;
        }

        getline(ss, d.satuan, ',');

        df.push_back(d);
    }

    file.close();

    cout << "Jumlah data terbaca: "
         << df.size() << endl;

    return true;
}

void ringkasanDataset() {

    set<string> gedung;
    set<string> parameter;

    for (auto d : df) {
        gedung.insert(d.lokasi);
        parameter.insert(d.parameter);
    }

    cout << "\n=== RINGKASAN DATA ===\n";

    cout << "Jumlah Record : "
         << df.size() << endl;

    cout << "Jumlah Gedung : "
         << gedung.size() << endl;

    cout << "Jumlah Parameter : "
         << parameter.size() << endl;
}

void statistikData() {

    cout << "\n=== STATISTIK ===\n";

    set<string> parameterSet;

    for (auto d : df)
        parameterSet.insert(d.parameter);

    for (auto p : parameterSet) {

        double total = 0;
        double maksimum = -999999;
        double minimum = 999999;
        int jumlah = 0;

        for (auto d : df) {

            if (d.parameter == p) {

                total += d.nilai;
                jumlah++;

                if (d.nilai > maksimum)
                    maksimum = d.nilai;

                if (d.nilai < minimum)
                    minimum = d.nilai;
            }
        }

        if (jumlah == 0)
            continue;

        cout << "\n" << p << endl;

        cout << "Rata-rata : "
             << fixed
             << setprecision(2)
             << total / jumlah
             << endl;

        cout << "Maksimum  : "
             << maksimum
             << endl;

        cout << "Minimum   : "
             << minimum
             << endl;
    }
}

void analisisKampus() {

    cout << "\n=== ANALISIS KAMPUS ===\n";

    set<string> parameterSet;

    for (auto d : df)
        parameterSet.insert(d.parameter);

    for (auto p : parameterSet) {

        map<string, pair<double,int>> gedungData;

        for (auto d : df) {

            if (d.parameter == p) {

                gedungData[d.lokasi].first += d.nilai;
                gedungData[d.lokasi].second++;
            }
        }

        string lokasiTertinggi;
        double nilaiTertinggi = -1;

        for (auto item : gedungData) {

            double rata =
                item.second.first /
                item.second.second;

            if (rata > nilaiTertinggi) {

                nilaiTertinggi = rata;
                lokasiTertinggi = item.first;
            }
        }

        cout << p
             << " Tertinggi : "
             << lokasiTertinggi
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

    map<string, pair<double,int>> energyData;

    for (auto d : df) {

        if (d.parameter == "Energy") {

            energyData[d.lokasi].first += d.nilai;
            energyData[d.lokasi].second++;
        }
    }

    double maksimum = 0;

    map<string,double> rataGedung;

    for (auto item : energyData) {

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

        cout << "Gagal membuat laporan!\n";
        return;
    }

    set<string> gedung;
    set<string> parameter;

    for (auto d : df) {

        gedung.insert(d.lokasi);
        parameter.insert(d.parameter);
    }

    file << "LAPORAN SUSTAINABILITY UNESA\n\n";

    file << "Jumlah Record : "
         << df.size() << "\n";

    file << "Jumlah Gedung : "
         << gedung.size() << "\n";

    file << "Jumlah Parameter : "
         << parameter.size() << "\n\n";

    for (auto p : parameter) {

        double total = 0;
        double maksimum = -999999;
        double minimum = 999999;
        int jumlah = 0;

        for (auto d : df) {

            if (d.parameter == p) {

                total += d.nilai;
                jumlah++;

                if (d.nilai > maksimum)
                    maksimum = d.nilai;

                if (d.nilai < minimum)
                    minimum = d.nilai;
            }
        }

        file << p << "\n";

        file << "Rata-rata : "
             << fixed
             << setprecision(2)
             << total / jumlah
             << "\n";

        file << "Maksimum : "
             << maksimum
             << "\n";

        file << "Minimum : "
             << minimum
             << "\n\n";
    }

    file.close();

    cout << "\nLaporan berhasil disimpan!\n";
}

int main() {

    if (!bacaCSV("../dataset/sustainability_data.csv"))
        return 0;

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
            ringkasanDataset();
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