# 🚢 Problem Statement 0: The Ministry of Cargo Confusion

[![Difficulty](https://img.shields.io/badge/Difficulty-Complete%20Beginner%20to%20Intermediate-2ea44f?style=flat-square)](#)
[![Concepts](https://img.shields.io/badge/Concepts-Loops%20|%20Arrays%20|%20File%20I%2FO-0d6efd?style=flat-square)](#)
[![Implementation](https://img.shields.io/badge/Implementation-From%20Scratch-e74c3c?style=flat-square)](#)
[![Language](https://img.shields.io/badge/Language-Any-9c27b0?style=flat-square)](#)

---

## 📖 Background

The **Ministry of Extremely Important Cargo Affairs (MEICA)** proudly announced that the country's smartest cargo port was now **100% automated**.

Unfortunately, during the inauguration ceremony, **five ministers pressed the "Start Automation" button at the exact same time.**

The software immediately crashed.

Now hundreds of cargo ships are waiting outside the port carrying food, electronics, cricket bats, instant noodles, and suspiciously large numbers of election campaign banners.

The port manager has only one request:

> *"Please build something before another committee is formed to investigate why the first software stopped working."*

**Your task is to build the first version of the CargoPort Management System before the next shipment arrives.**

---

## 🎯 Your Mission

Build a **program** that helps the port manager determine whether the incoming shipment can be accommodated within the available storage capacity.

This means you write a single program file (e.g. `solution.py`, `solution.cpp`, `solution.java`) and run it in your terminal. That's it.

- You may use **any programming language** — Python, C++, C, Java, etc.
- **All input and output happens in the terminal.** The user types values, your program prints results.
- **No GUI, no web app, no framework** — just your code and the command line.
- **No databases or external libraries** should be used.

> 💡 **What does this look like?**
> You write your code → you run it (`python solution.py` or `./solution`) → it asks for input in the terminal → it prints the output in the terminal. Done.

---

## 📦 Level 1 — Counting the Cargo

> *The workers have managed to unload the containers, but they have absolutely no idea how heavy the shipment is.*

Your program should:

1. Ask the worker **how many containers** have arrived.
2. Read the **weight of each container**.
3. Calculate and display:
   - ✅ **Total shipment weight**
   - ✅ **Average container weight**
   - ✅ **Heaviest container**
   - ✅ **Lightest container**
   - ✅ **Whether the shipment is Heavy (≥200) or Light (<200)**

### 💡 Concepts Used
| Concept | Description |
|---|---|
| Variables | Storing container weights and computed values |
| Input / Output | Reading data from the user and displaying results |
| Arithmetic Operators | Calculating totals, averages, and comparisons |
| `for` / `while` Loops | Iterating through containers |
| `if` Statements | Classifying shipments as Heavy or Light |
| Min / Max | Finding the heaviest and lightest containers |

### 📋 Examples

<details>
<summary><strong>Test Case 1</strong></summary>
<br>

**Input:**
```
Enter number of containers: 5
Enter weight of container 1: 50
Enter weight of container 2: 120
Enter weight of container 3: 80
Enter weight of container 4: 45
Enter weight of container 5: 30
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
<summary><strong>Test Case 2</strong></summary>
<br>

**Input:**
```
Enter number of containers: 3
Enter weight of container 1: 20
Enter weight of container 2: 35
Enter weight of container 3: 40
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
<summary><strong>Test Case 3</strong></summary>
<br>

**Input:**
```
Enter number of containers: 2
Enter weight of container 1: 100
Enter weight of container 2: 100
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

---

## ⚖️ Level 2 — Can the Port Handle It?

> *The workers now know the shipment weight. Unfortunately… nobody knows whether the port actually has enough storage space!*

Modify your program so that it also asks for:

- ✅ **Maximum storage capacity of the port**

After calculating the shipment weight, determine **whether the shipment can be unloaded**.

### 💡 Concepts Used

Everything from Level 1, plus:

| Concept | Description |
|---|---|
| Multiple Conditions | Combining weight and capacity checks |
| Counters | Tracking accepted vs. rejected shipments |
| Decision Making | Determining if the port can accommodate cargo |
| Combined Logic | Integrating calculations with program flow |

### 📋 Examples

<details>
<summary><strong>Test Case 1</strong></summary>
<br>

**Input:**
```
Enter maximum port storage capacity: 300
Enter number of containers: 4
Enter weight of container 1: 90
Enter weight of container 2: 75
Enter weight of container 3: 60
Enter weight of container 4: 50
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
<summary><strong>Test Case 2</strong></summary>
<br>

**Input:**
```
Enter maximum port storage capacity: 200
Enter number of containers: 3
Enter weight of container 1: 100
Enter weight of container 2: 80
Enter weight of container 3: 90
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
<summary><strong>Test Case 3</strong></summary>
<br>

**Input:**
```
Enter maximum port storage capacity: 150
Enter number of containers: 3
Enter weight of container 1: 50
Enter weight of container 2: 50
Enter weight of container 3: 50
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

---

## 🧠 Level 3 — Smart Cargo Terminal

> *The committee investigating the software failure has finally finished its report. Their recommendation? "Make the software smarter."*

**Choose any three** of the following improvements:

| # | Feature | Description |
|---|---|---|
| 1 | 📊 **Sorted Display** | Display the container weights in sorted order |
| 2 | 🚢 **Multi-Ship Processing** | Process multiple ships without restarting the program |
| 3 | 📈 **Bar Chart** | Draw a simple bar chart using `*` characters |
| 4 | 💾 **Save Report** | Save the shipment report to a file |
| 5 | 📂 **Read from File** | Read shipment data from a file |
| 6 | 🔍 **Search** | Search for a specific container by weight or ID |
| 7 | 🏆 **Nth Heaviest** | Ask the user for N and display the Nth heaviest container |
| 8 | 📋 **Menu Interface** | Add a menu-driven interface for navigation |
| 9 | 🎨 **Your Own Feature** | Add your own creative feature! |

### 💡 Concepts Used

| Concept | Description |
|---|---|
| Arrays / Vectors / Lists | Storing and manipulating container data |
| Sorting | Ordering containers by weight |
| Menus | User-driven navigation through features |
| File Handling | Reading from and writing to files |
| Functions | Modular, reusable code blocks |
| Modular Programming | Organizing code into logical components |
| Creativity & Problem Solving | Designing your own features |

### 📋 Feature Examples

*For all examples below, assume the following containers were entered:*
**Containers:** `[50, 120, 80, 45, 30]`

---

<details>
<summary><strong>Feature 1 — 📊 Sorted Display</strong></summary>
<br>

**Output:**
```
Containers in sorted order:
1. 30
2. 45
3. 50
4. 80
5. 120
```
</details>

<details>
<summary><strong>Feature 2 — 🚢 Multi-Ship Processing</strong></summary>
<br>

**Input & Output (interleaved):**
```
Processing Ship 1...
Enter number of containers: 3
Enter weight of container 1: 50
Enter weight of container 2: 70
Enter weight of container 3: 60

Total Shipment Weight: 180
Classification: Light

Process another ship? (yes/no): yes

Processing Ship 2...
Enter number of containers: 2
Enter weight of container 1: 150
Enter weight of container 2: 200

Total Shipment Weight: 350
Classification: Heavy

Process another ship? (yes/no): no

Total ships processed: 2
```
</details>

<details>
<summary><strong>Feature 3 — 📈 Bar Chart</strong></summary>
<br>

```
Container Weight Bar Chart:

Container 1 (50)  : **********
Container 2 (120) : ************************
Container 3 (80)  : ****************
Container 4 (45)  : *********
Container 5 (30)  : ******

(Each * represents 5 units)
```
</details>

<details>
<summary><strong>Feature 4 — 💾 Save Report</strong></summary>
<br>

**Input:**
```
Save report to file? (yes/no): yes
Enter filename: shipment_report.txt
```

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
</details>

<details>
<summary><strong>Feature 5 — 📂 Read from File</strong></summary>
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

**Input:**
```
Enter filename to read from: containers.txt
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
</details>

<details>
<summary><strong>Feature 6 — 🔍 Search</strong></summary>
<br>

**Input:** `80`
```
Search for container by weight: 80
```
**Output:**
```
Container found!
Container 3 has weight 80
```

**Input:** `99`
```
Search for container by weight: 99
```
**Output:**
```
No container found with weight 99
```
</details>

<details>
<summary><strong>Feature 7 — 🏆 Nth Heaviest</strong></summary>
<br>

**Input:** `1`
```
Enter N to find the Nth heaviest container: 1
```
**Output:**
```
The 1st heaviest container has weight: 120
```

**Input:** `3`
```
Enter N to find the Nth heaviest container: 3
```
**Output:**
```
The 3rd heaviest container has weight: 50
```

**Input:** `6`
```
Enter N to find the Nth heaviest container: 6
```
**Output:**
```
Invalid input: Only 5 containers exist.
```
</details>

<details>
<summary><strong>Feature 8 — 📋 Menu Interface</strong></summary>
<br>

**Input & Output (interleaved):**
```
CargoPort Management System

1. Enter container data
2. View shipment report
3. Sort containers
4. Search container
5. Find Nth heaviest
6. Save report to file
7. Load data from file
8. Exit

Select an option: 2

Total Shipment Weight: 325
Average Container Weight: 65.0
Heaviest Container: 120
Lightest Container: 30
Classification: Heavy

Press Enter to return to menu...
```
</details>

---

## 🚧 Constraints

- Use **any programming language** (Python, C++, C, Java, etc.).
- Your solution should be a **single program file** (or a few files if needed) — not a project built with a framework.
- **Everything runs in the terminal** — your program reads input from the user and prints output. No windows, no buttons, no browser.
- **No external databases or libraries** are required.
- Focus on writing **clean, readable code**.

> ⚠️ **NO GUI IS REQUIRED FOR ANY LEVEL.** Write a program, run it in the terminal, and interact through typed input/output. That's all we're looking for.

---

## 📋 Evaluation

| Criteria | Weight |
|---|---|
| 🎯 **Correctness** | 40% |
| ⚙️ **Code Quality** | 20% |
| 📖 **Readability** | 15% |
| 🖥️ **User Experience** | 15% |
| 🎨 **Creativity** | 10% |

---

## ✅ Submission Checklist

- [ ] **Level 1** — Basic cargo counting working correctly
- [ ] **Level 2** — Port capacity check implemented
- [ ] **Level 3** — At least 3 smart features added
- [ ] **Test cases** demonstrating all functionality
- [ ] **Documentation** explaining your approach (optional but recommended)
- [ ] **Clean, commented code** with good structure
- [ ] **Error handling** for invalid inputs

---

## 🚀 Getting Started

1. **Read the problem statement** carefully — understand each level
2. **Start with Level 1** — get basic input/output working
3. **Test with the example cases** provided above
4. **Move to Level 2** — add capacity checks
5. **Pick 3 features from Level 3** — implement and test
6. **Document your approach** — explain your design choices

---

## 📚 Learning Objectives

By completing this challenge, you'll learn:

### ⚙️ Programming Skills
- Reading user input and displaying formatted output
- Working with loops, conditions, and arithmetic
- Using arrays/lists to store and process data
- File handling for reading and writing reports

### 🧠 Problem-Solving
- Breaking complex problems into smaller parts
- Testing and validating with different inputs
- Handling edge cases (zero containers, capacity overflow, etc.)
- Designing user-friendly terminal interfaces

---

*Remember: The goal is learning, not perfection. Start simple and build up! 🌱*
