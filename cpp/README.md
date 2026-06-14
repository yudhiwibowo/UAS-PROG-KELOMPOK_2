# C++ Implementation

## Description

This C++ program is used to analyze UNESA campus sustainability data based on a dataset stored in a CSV file. The program provides an interactive menu to display data summaries, parameter statistics, building analysis, sustainability ratings, and generate analysis reports.

## File

* `main.cpp`: Main program for sustainability analysis.

## Features

1. Read the dataset from a CSV file.
2. Display a dataset summary.
3. Calculate statistics for each parameter.
4. Determine the building with the highest average value for each parameter.
5. Provide Sustainability Ratings (Green, Warning, Critical).
6. Save analysis results to a report file.

## Compilation Guide

```bash
g++ main.cpp -o main
```

## How to Run

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

The program generates a report:

```text
../output/sustainability_report.txt
```
