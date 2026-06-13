import pandas as pd

FILE_DATA = "../dataset/sustainability_data.csv"


def hitung_rating(persen):
    if persen <= 40:
        return "Green"
    elif persen <= 70:
        return "Warning"
    else:
        return "Critical"


df = pd.read_csv(FILE_DATA)

while True:

    print("\n===== ANALISIS SUSTAINABILITY UNESA =====")
    print("1. Ringkasan Dataset")
    print("2. Statistik Data")
    print("3. Analisis Kampus")
    print("4. Sustainability Rating")
    print("5. Simpan Laporan")
    print("0. Keluar")

    pilih = input("Pilih Menu : ")

    if pilih == "1":

        print("\n=== RINGKASAN DATA ===")
        print("Jumlah Record :", len(df))
        print("Jumlah Gedung :", df["lokasi"].nunique())
        print("Jumlah Parameter :", df["parameter"].nunique())

    elif pilih == "2":

        print("\n=== STATISTIK ===")

        for p in df["parameter"].unique():

            data = df[df["parameter"] == p]["nilai"]

            print(f"\n{p}")
            print("Rata-rata :", round(data.mean(), 2))
            print("Maksimum  :", round(data.max(), 2))
            print("Minimum   :", round(data.min(), 2))

    elif pilih == "3":

        print("\n=== ANALISIS KAMPUS ===")

        for p in df["parameter"].unique():

            data = df[df["parameter"] == p]

            avg_gedung = (
                data.groupby("lokasi")["nilai"]
                .mean()
                .reset_index()
            )

            tertinggi = avg_gedung.loc[
                avg_gedung["nilai"].idxmax()
            ]

            print(
                f"{p} Tertinggi : "
                f"{tertinggi['lokasi']} "
                f"({tertinggi['nilai']:.2f})"
            )

    elif pilih == "4":

        print("\n=== SUSTAINABILITY RATING ===")

        energy = df[df["parameter"] == "Energy"]

        avg_gedung = (
            energy.groupby("lokasi")["nilai"]
            .mean()
            .reset_index()
        )

        maksimum = avg_gedung["nilai"].max()

        for _, row in avg_gedung.iterrows():

            persen = (row["nilai"] / maksimum) * 100

            print(
                row["lokasi"],
                "-",
                hitung_rating(persen)
            )

    elif pilih == "5":

        with open(
            "../output/laporan_sustainability.txt",
            "w",
            encoding="utf-8"
        ) as f:

            f.write("LAPORAN SUSTAINABILITY UNESA\n\n")

            f.write(
                f"Jumlah Record : {len(df)}\n"
            )

            f.write(
                f"Jumlah Gedung : "
                f"{df['lokasi'].nunique()}\n"
            )

            f.write(
                f"Jumlah Parameter : "
                f"{df['parameter'].nunique()}\n\n"
            )

            for p in df["parameter"].unique():

                data = df[
                    df["parameter"] == p
                ]["nilai"]

                f.write(f"{p}\n")
                f.write(
                    f"Rata-rata : {data.mean():.2f}\n"
                )
                f.write(
                    f"Maksimum : {data.max():.2f}\n"
                )
                f.write(
                    f"Minimum : {data.min():.2f}\n\n"
                )

        print(
            "\nLaporan berhasil disimpan!"
        )

    elif pilih == "0":
        break

    else:
        print("Pilihan tidak valid!")