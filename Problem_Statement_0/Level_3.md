# 🧠 Level 3 — Smart Cargo Terminal

[![Difficulty](https://img.shields.io/badge/Difficulty-Intermediate-e67e22?style=flat-square)](#)
[![Concepts](https://img.shields.io/badge/Concepts-Arrays%20|%20Sorting%20|%20File%20I%2FO-0d6efd?style=flat-square)](#)

---

## Background

The committee investigating the software failure has finally finished its report. Their recommendation?

> *"Make the software smarter."*

---

## Your Task

Build on your Level 1 program. **Implement** as many of the following features as possible:

| # | Feature | Description |
|---|---|---|
| 1 | **Sorted Display** | Display container weights in sorted order without using sort function |
| 2 | **Multi-Ship Processing** | Process multiple ships without restarting the program |
| 3 | **Bar Chart** | Draw a bar chart using `*` characters |
| 4 | **Save Report** | Save the shipment report to a file |
| 5 | **Read from File** | Read shipment data from a file |
| 6 | **Search** | Search for a container by weight |
| 7 | **Kth Heaviest** | Find the Kth heaviest container |
| 8 | **Your Own Feature** | Add your own creative feature |

---

## Rules

Same as previous levels:
- Any programming language
- Single program file, runs in terminal
- No GUI, no frameworks, no external libraries

---

## Concepts You'll Use

| Concept | Description |
|---|---|
| Arrays / Lists | Storing and manipulating container data |
| Sorting | Ordering containers by weight |
| File Handling | Reading from and writing to files |
| Functions | Modular, reusable code blocks |

---

## Feature Examples & Test Cases

*For all examples, assume these containers were entered:*
**Containers:** `5` containers with weights `50, 120, 80, 45, 30`

---

<details>
<summary><strong>Feature 1 — Sorted Display</strong></summary>
<br>

**Input:** *(no additional input — uses already entered data)*

**Output:**
```
Containers in sorted order:
1. 30
2. 45
3. 50
4. 80
5. 120
```

---

**🧪 Test Case 2:**

Containers: `3` with weights `50, 50, 50`

**Output:**
```
Containers in sorted order:
1. 50
2. 50
3. 50
```

---

**🧪 Test Case 3:**

Containers: `4` with weights `10, 20, 30, 40`

**Output:**
```
Containers in sorted order:
1. 10
2. 20
3. 30
4. 40
```

---

**🧪 Test Case 4:**

Containers: `4` with weights `40, 30, 20, 10`

**Output:**
```
Containers in sorted order:
1. 10
2. 20
3. 30
4. 40
```
</details>

<details>
<summary><strong>Feature 2 — Multi-Ship Processing</strong></summary>
<br>

Your program asks if the user wants to process another ship after each one.

**Input (Ship 1):**
```
3
50
70
60
```
**Output (Ship 1):**
```
Total Shipment Weight: 180
Classification: Light
```

**Input (continue?):** `yes`

**Input (Ship 2):**
```
2
150
200
```
**Output (Ship 2):**
```
Total Shipment Weight: 350
Classification: Heavy
```

**Input (continue?):** `no`

**Output (final):**
```
Total ships processed: 2
```

---

**🧪 Test Case 2:**

**Input (Ship 1):**
```
1
500
```
**Output (Ship 1):**
```
Total Shipment Weight: 500
Classification: Heavy
```

**Input (continue?):** `no`

**Output (final):**
```
Total ships processed: 1
```
</details>

<details>
<summary><strong>Feature 3 — Bar Chart</strong></summary>
<br>

**Input:** *(no additional input)*

**Output:**
```
Container Weight Bar Chart:

Container 1 (50)  : **********
Container 2 (120) : ************************
Container 3 (80)  : ****************
Container 4 (45)  : *********
Container 5 (30)  : ******

(Each * represents 5 units)
```

---

**🧪 Test Case 2:**

Containers: `1` with weight `25`

**Output:**
```
Container Weight Bar Chart:

Container 1 (25)  : *****

(Each * represents 5 units)
```
</details>

<details>
<summary><strong>Feature 4 — Save Report</strong></summary>
<br>

**Input:**
```
yes
shipment_report.txt
```
- Line 1: whether to save (`yes` / `no`)
- Line 2: filename

**Output:**
```
Report saved to shipment_report.txt
```

Contents of `shipment_report.txt`:
```
Total Shipment Weight: 325
Average Container Weight: 65.0
Heaviest Container: 120
Lightest Container: 30
Classification: Heavy
```

---

**🧪 Test Case 2:**

**Input:**
```
no
```

*(No file is created, program continues normally)*
</details>

<details>
<summary><strong>Feature 5 — Read from File</strong></summary>
<br>

Given a file `containers.txt` with contents:
```
5
50
120
80
45
30
```
*(First line = number of containers, remaining lines = weights)*

**Input:**
```
containers.txt
```

**Output:**
```
Loaded 5 containers from containers.txt
Weights: 50, 120, 80, 45, 30

Total Shipment Weight: 325
Average Container Weight: 65.0
Heaviest Container: 120
Lightest Container: 30
Classification: Heavy
```

---

**🧪 Test Case 2:**

File `single.txt`:
```
1
99
```

**Input:**
```
single.txt
```

**Output:**
```
Loaded 1 containers from single.txt
Weights: 99

Total Shipment Weight: 99
Average Container Weight: 99.0
Heaviest Container: 99
Lightest Container: 99
Classification: Light
```
</details>

<details>
<summary><strong>Feature 6 — Search</strong></summary>
<br>

**Input:**
```
80
```

**Output:**
```
Container found!
Container 3 has weight 80
```

---

**Input (not found):**
```
99
```

**Output:**
```
No container found with weight 99
```

---

**🧪 Test Case 3:**

Containers: `4` with weights `50, 80, 50, 30`

**Input:**
```
50
```

**Output:**
```
Container found!
Container 1 has weight 50
```
*(Finding the first match is sufficient)*

---

**🧪 Test Case 4:**

**Input:**
```
30
```

**Output:**
```
Container found!
Container 5 has weight 30
```
</details>

<details>
<summary><strong>Feature 7 — Kth Heaviest</strong></summary>
<br>

**Input:**
```
1
```
**Output:**
```
The 1st heaviest container has weight: 120
```

---

**Input:**
```
3
```
**Output:**
```
The 3rd heaviest container has weight: 50
```

---

**Input:**
```
5
```
**Output:**
```
The 5th heaviest container has weight: 30
```

---

**🧪 Test Case 4:**

**Input:**
```
6
```
**Output:**
```
Invalid input: Only 5 containers exist.
```

---

**🧪 Test Case 5:**

**Input:**
```
0
```
**Output:**
```
Invalid input: N must be at least 1.
```

---

**🧪 Test Case 6:**

**Input:**
```
-1
```
**Output:**
```
Invalid input: N must be at least 1.
```
</details>

---

*Finished all three levels? Great job — you've built a working Cargo Management System from scratch!*
