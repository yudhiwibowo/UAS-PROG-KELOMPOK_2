# C++ Implementation

## Description

This C++ program is used to analyze UNESA campus sustainability data based on a dataset stored in a CSV file. The program provides an interactive menu to display dataset summaries, parameter statistics, building analysis, sustainability ratings, and the generation of analysis reports.

## File

* `main.cpp` : Main program for sustainability analysis.

## Features

1. Reads the dataset from a CSV file.
2. Displays a dataset summary.
3. Calculates statistics for each parameter.
4. Identifies the building with the highest average value for each parameter.
5. Provides Sustainability Ratings (Green, Warning, Critical).
6. Saves the analysis results to a report file.

## Compilation

```bash
g++ main.cpp -o main
```

## Running the Program

Windows:

```bash
main.exe
```

Linux/macOS:

```bash
./main
```

## Data Structures Used

* Struct
* Vector
* Set
* Map
* File Handling
* String Stream

## Input

The program reads data from:

```text
../dataset/sustainability_data.csv
```

## Output

The program generates a report file:

```text
../output/laporan_sustainability.txt
```
