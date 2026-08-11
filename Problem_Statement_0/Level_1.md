# 📦 Level 1 — Counting the Cargo

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

The workers have managed to unload the containers, but they have absolutely no idea how heavy the shipment is.

Write a program that:

1. Reads the **number of containers** `N`.
2. Reads the **weight of each container**, one per line.
3. Calculates and prints:
   - **Total shipment weight** — sum of all weights
   - **Average container weight** — total ÷ N
   - **Heaviest container** — maximum weight
   - **Lightest container** — minimum weight
   - **Classification** — `Heavy` if total ≥ 200, otherwise `Light`

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

Your program should prompt the user (e.g. `"Enter number of containers: "`), but test cases only show the raw numbers to keep things clean.

**Example — how it works in practice:**

Your terminal looks like:
```
Enter number of containers: 3
Enter weight of container 1: 50
Enter weight of container 2: 70
Enter weight of container 3: 60

Total Shipment Weight: 180
```

But in the test case, we write:

**Input:**
```
3
50
70
60
```
**Output:**
```
Total Shipment Weight: 180
```

---

## Input Format

```
N
w1
w2
...
wN
```
- Line 1: `N` — number of containers (integer, 1 ≤ N ≤ 1000)
- Lines 2 to N+1: `wi` — weight of the i-th container (integer or decimal)

## Output Format

```
Total Shipment Weight: <value>
Average Container Weight: <value>
Heaviest Container: <value>
Lightest Container: <value>
Classification: <Heavy/Light>
```

---

## Concepts You'll Use

| Concept | Description |
|---|---|
| Variables | Storing weights and computed values |
| Input / Output | Reading from terminal, printing results |
| Arithmetic | Sum, division, comparison |
| Loops | Iterating through N containers |
| Conditions | Classifying as Heavy or Light |
| Min / Max | Finding heaviest and lightest |

---

## Test Cases

<details>
<summary><strong>🧪 Test Case 1</strong></summary>
<br>

**Input:**
```
5
50
120
80
45
30
```

**Output:**
```
Total Shipment Weight: 325
Average Container Weight: 65.0
Heaviest Container: 120
Lightest Container: 30
Classification: Heavy
```
</details>

<details>
<summary><strong>🧪 Test Case 2</strong></summary>
<br>

**Input:**
```
3
20
35
40
```

**Output:**
```
Total Shipment Weight: 95
Average Container Weight: 31.67
Heaviest Container: 40
Lightest Container: 20
Classification: Light
```
</details>

<details>
<summary><strong>🧪 Test Case 3</strong></summary>
<br>

**Input:**
```
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
```
</details>

<details>
<summary><strong>🧪 Test Case 4</strong></summary>
<br>

**Input:**
```
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
```
</details>

<details>
<summary><strong>🧪 Test Case 5</strong></summary>
<br>

**Input:**
```
1
250
```

**Output:**
```
Total Shipment Weight: 250
Average Container Weight: 250.0
Heaviest Container: 250
Lightest Container: 250
Classification: Heavy
```
</details>

<details>
<summary><strong>🧪 Test Case 6</strong></summary>
<br>

**Input:**
```
4
50
50
50
50
```

**Output:**
```
Total Shipment Weight: 200
Average Container Weight: 50.0
Heaviest Container: 50
Lightest Container: 50
Classification: Heavy
```
</details>

<details>
<summary><strong>🧪 Test Case 7</strong></summary>
<br>

**Input:**
```
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
```
</details>

<details>
<summary><strong>🧪 Test Case 8</strong></summary>
<br>

**Input:**
```
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
```
</details>

---

*Once you're confident Level 1 works, move on to [Level 2](Level_2.md).*
