# 🚂 Railway Route & Dispatch Simulator

A C++ console-based railway management simulator built as a DSA (Data Structures & Algorithms) project.

## 📌 Project Overview

This project simulates a railway dispatch system where trains are managed across stations, platforms, and routes. Every feature is built using a core DSA concept — no STL containers used.

## 🧠 DSA Concepts Used

| Phase | Topic | Feature |
|:---:|:---|:---|
| 1 | OOP + Arrays | Train, Station, RailwaySystem classes |
| 2 | Searching | Find train by number (Linear + Binary Search) |
| 3 | Sorting | Sort trains by priority (Bubble + Selection Sort) |
| 4 | Linked List | Train coaches + unlimited train list |
| 5 | Queue | Platform waiting line (FIFO) |
| 6 | Stack | Shunting yard / siding track (LIFO) |
| 7 | BST | Fast train registry with In-Order display |

## 📁 Folder Structure

```
railway-simulator-trainnn/
├── src/           ← All header files (.h) go here
├── data/          ← trains.txt sample data file
└── main.cpp       ← Entry point
```

## ⚙️ How to Compile & Run

```bash
g++ main.cpp -o simulator
./simulator
```

## 👥 Team

| Member | Branch | Responsibility |
|:---|:---|:---|
| TBD | `dev-member1` | TBD |
| TBD | `dev-member2` | TBD |
| TBD | `dev-member3` | TBD |

## 📋 Constraints

- No STL containers (`vector`, `map`, `queue`) — all data structures are built from scratch
- No dynamic memory (`new` / `delete`) until the Linked List phase
- Max 10 Stations, 5 Platforms per Station, 20 Coaches per Train
- Train numbers must be unique and > 0
