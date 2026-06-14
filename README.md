# UNESA Sustainability Analysis System

## Team Members

* Muhammad Yudhi Wahyu Wibowo
* Indryana Azaki
* Azam Irfansyah
* Four Rezeki Waruwu

## Description

This project is a sustainability analysis system for UNESA that utilizes IoT sensor data to monitor various environmental parameters, including energy consumption, water usage, CO₂ emissions, and waste production.

The system was developed using two programming languages, **C++** and **Python**, both providing the same functionality to analyze data, generate statistical information, identify buildings with the highest consumption levels, assign sustainability ratings, and save analysis results into a report file.

## How to Run the C++ Program

```bash
g++ main.cpp -o main
./main
```

## How to Run the Python Program

```bash
python main.py
```

## Analysis Summary

Based on the analysis of the UNESA sustainability dataset:

* **Total Records:** 29,200 records
* **Total Buildings:** 20 buildings
* **Total Parameters:** 4 parameters (Energy, Water, CO₂, and Waste)
* The program successfully reads the dataset and performs statistical analysis, including average, maximum, and minimum values for each parameter.
* The program identifies the building with the highest average energy consumption.
* The program identifies the building with the highest average water usage.
* The program identifies the building with the highest average CO₂ emissions.
* The program identifies the building with the highest average waste production.
* The program classifies each building into Sustainability Rating categories:

  * **Green** (0–40%)
  * **Warning** (40–70%)
  * **Critical** (>70%)
* All analysis results can be saved into the `laporan_sustainability.txt` report file.

## Comparison Between C++ and Python

| Aspect          | C++                       | Python                              |
| --------------- | ------------------------- | ----------------------------------- |
| Execution Speed | Faster                    | Slower                              |
| Ease of Coding  | More complex syntax       | Simpler syntax                      |
| Lines of Code   | More lines required       | Fewer lines required                |
| CSV Processing  | Requires manual parsing   | Easy with the Pandas library        |
| Debugging       | Relatively more difficult | Easier                              |
| Memory Usage    | More efficient            | Higher memory consumption           |
| Best Suited For | High-performance systems  | Data analysis and rapid development |

## Presentation Video

(To be added later)
