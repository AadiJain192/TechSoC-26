# 📦 Level 1 — Counting the Cargo & Capacity

[![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-2ea44f?style=flat-square)](#)
[![Concepts](https://img.shields.io/badge/Concepts-Variables%20|%20Loops%20|%20Conditions-0d6efd?style=flat-square)](#)

---

## Background

The **Ministry of Extremely Important Cargo Affairs (MEICA)** proudly announced that the country's smartest cargo port was now **100% automated**.

Unfortunately, during the inauguration ceremony, **five ministers pressed the "Start Automation" button at the exact same time.** The software immediately crashed.

Now hundreds of cargo ships are waiting outside the port. The port manager has only one request:

> *"Please build something before another committee is formed to investigate why the first software stopped working."*

---

## Your Task

The workers have managed to unload the containers, but they have absolutely no idea how heavy the shipment is, nor whether the port actually has enough storage space to handle it!

Write a program that:

1. Reads the **maximum storage capacity** of the port `C`.
2. Reads the **number of containers** `N`.
3. Reads the **weight of each container**, one per line.
4. Calculates and prints:
   - **Total shipment weight** — sum of all weights
   - **Average container weight** — total ÷ N
   - **Heaviest container** — maximum weight
   - **Lightest container** — minimum weight
   - **Classification** — `Heavy` if total ≥ 200, otherwise `Light`
   - **Port Capacity** — the capacity that was input
   - **Status** — `Shipment can be unloaded` if total weight ≤ capacity, otherwise `Shipment exceeds port capacity`

---

## Rules

- Use **any programming language** (Python, C++, C, Java, etc.)
- Write a single program file and run it in your terminal
- **No GUI, no web app, no framework** — just code and the command line
- **No external libraries or databases**

> You write your code → run it (`python solution.py` or `./solution`) → it reads input → prints output. That's it.

---

## How to Read the Test Cases

- **Input** shows only the **raw values** you type — just numbers, one per line.
- **Output** shows what your program should print.

Your program should prompt the user (e.g. `"Enter capacity: "`), but test cases only show the raw numbers to keep things clean.

---

## Input Format

```
C
N
w1
w2
...
wN
```
- Line 1: `C` — maximum port storage capacity (integer)
- Line 2: `N` — number of containers (integer, 1 ≤ N ≤ 1000)
- Lines 3 to N+2: `wi` — weight of the i-th container (integer or decimal)

## Output Format

```
Total Shipment Weight: <value>
Average Container Weight: <value>
Heaviest Container: <value>
Lightest Container: <value>
Classification: <Heavy/Light>
Port Capacity: <value>
Status: <Shipment can be unloaded / Shipment exceeds port capacity>
```

---

## Concepts You'll Use

| Concept | Description |
|---|---|
| Variables | Storing weights and computed values |
| Input / Output | Reading from terminal, printing results |
| Arithmetic | Sum, division, comparison |
| Loops | Iterating through N containers |
| Conditions | Classifying weight and checking against capacity |
| Min / Max | Finding heaviest and lightest |

---

## Test Cases

<details>
<summary><strong>🧪 Test Case 1</strong></summary>
<br>

**Input:**
```
300
4
90
75
60
50
```

**Output:**
```
Total Shipment Weight: 275
Average Container Weight: 68.75
Heaviest Container: 90
Lightest Container: 50
Classification: Heavy
Port Capacity: 300
Status: Shipment can be unloaded
```
</details>

<details>
<summary><strong>🧪 Test Case 2</strong></summary>
<br>

**Input:**
```
200
3
100
80
90
```

**Output:**
```
Total Shipment Weight: 270
Average Container Weight: 90.0
Heaviest Container: 100
Lightest Container: 80
Classification: Heavy
Port Capacity: 200
Status: Shipment exceeds port capacity
```
</details>

<details>
<summary><strong>🧪 Test Case 3</strong></summary>
<br>

**Input:**
```
150
3
50
50
50
```

**Output:**
```
Total Shipment Weight: 150
Average Container Weight: 50.0
Heaviest Container: 50
Lightest Container: 50
Classification: Light
Port Capacity: 150
Status: Shipment can be unloaded
```
</details>

<details>
<summary><strong>🧪 Test Case 4</strong></summary>
<br>

**Input:**
```
150
3
50
50
51
```

**Output:**
```
Total Shipment Weight: 151
Average Container Weight: 50.33
Heaviest Container: 51
Lightest Container: 50
Classification: Light
Port Capacity: 150
Status: Shipment exceeds port capacity
```
</details>

<details>
<summary><strong>🧪 Test Case 5</strong></summary>
<br>

**Input:**
```
500
1
100
```

**Output:**
```
Total Shipment Weight: 100
Average Container Weight: 100.0
Heaviest Container: 100
Lightest Container: 100
Classification: Light
Port Capacity: 500
Status: Shipment can be unloaded
```
</details>

<details>
<summary><strong>🧪 Test Case 6</strong></summary>
<br>

**Input:**
```
50
1
300
```

**Output:**
```
Total Shipment Weight: 300
Average Container Weight: 300.0
Heaviest Container: 300
Lightest Container: 300
Classification: Heavy
Port Capacity: 50
Status: Shipment exceeds port capacity
```
</details>

<details>
<summary><strong>🧪 Test Case 7</strong></summary>
<br>

**Input:**
```
10000
3
10
20
30
```

**Output:**
```
Total Shipment Weight: 60
Average Container Weight: 20.0
Heaviest Container: 30
Lightest Container: 10
Classification: Light
Port Capacity: 10000
Status: Shipment can be unloaded
```
</details>

<details>
<summary><strong>🧪 Test Case 8</strong></summary>
<br>

**Input:**
```
1000
4
100
100
100
100
```

**Output:**
```
Total Shipment Weight: 400
Average Container Weight: 100.0
Heaviest Container: 100
Lightest Container: 100
Classification: Heavy
Port Capacity: 1000
Status: Shipment can be unloaded
```
</details>

<details>
<summary><strong>🧪 Test Case 9</strong></summary>
<br>

**Input:**
```
500
2
100
100
```

**Output:**
```
Total Shipment Weight: 200
Average Container Weight: 100.0
Heaviest Container: 100
Lightest Container: 100
Classification: Heavy
Port Capacity: 500
Status: Shipment can be unloaded
```
</details>

<details>
<summary><strong>🧪 Test Case 10</strong></summary>
<br>

**Input:**
```
200
2
100
99
```

**Output:**
```
Total Shipment Weight: 199
Average Container Weight: 99.5
Heaviest Container: 100
Lightest Container: 99
Classification: Light
Port Capacity: 200
Status: Shipment can be unloaded
```
</details>

<details>
<summary><strong>🧪 Test Case 11</strong></summary>
<br>

**Input:**
```
100
3
1
1
1
```

**Output:**
```
Total Shipment Weight: 3
Average Container Weight: 1.0
Heaviest Container: 1
Lightest Container: 1
Classification: Light
Port Capacity: 100
Status: Shipment can be unloaded
```
</details>

<details>
<summary><strong>🧪 Test Case 12</strong></summary>
<br>

**Input:**
```
300
6
10
20
30
40
50
60
```

**Output:**
```
Total Shipment Weight: 210
Average Container Weight: 35.0
Heaviest Container: 60
Lightest Container: 10
Classification: Heavy
Port Capacity: 300
Status: Shipment can be unloaded
```
</details>

---

*Once you're confident Level 1 works, move on to [Level 2](Level_2.md).*
