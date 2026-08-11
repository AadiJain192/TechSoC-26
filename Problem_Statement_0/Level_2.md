# ⚖️ Level 2 — Can the Port Handle It?

[![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-2ea44f?style=flat-square)](#)
[![Concepts](https://img.shields.io/badge/Concepts-Conditions%20|%20Decision%20Making-0d6efd?style=flat-square)](#)

---

## Background

The workers now know the shipment weight. Unfortunately… nobody knows whether the port actually has enough storage space!

---

## Your Task

Modify your Level 1 program so that it also:

1. Reads the **maximum storage capacity** of the port `C` (before reading container data).
2. After calculating the shipment report, determines whether the shipment can be unloaded:
   - If total weight ≤ capacity → `Shipment can be unloaded`
   - If total weight > capacity → `Shipment exceeds port capacity`

---

## Rules

Same as Level 1:
- Any programming language
- Single program file, runs in terminal
- No GUI, no frameworks, no external libraries

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
- Lines 3 to N+2: `wi` — weight of the i-th container

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

Everything from Level 1, plus:

| Concept | Description |
|---|---|
| Multiple Conditions | Combining weight and capacity checks |
| Decision Making | Determining if the port can accommodate cargo |
| Comparison Operators | Checking total weight against capacity |

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

---

*Once you're confident Level 2 works, move on to [Level 3](Level_3.md).*
