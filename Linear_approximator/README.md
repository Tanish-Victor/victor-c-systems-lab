# 🧮 Linear Approximation in C

A simple C program to approximate a function near a point using **linearization** (first-order Taylor expansion).  
This project is part of my computational physics foundation, building the bridge from math concepts to code.

---

## 🔹 Concept

Linear approximation formula:
F(x) = F(a) + F'(a)*(x-a)

Where:  
- `a` is the point near which the function is approximated  
- `f'(a)` is the derivative at `a`  
- `x` is the point where we want the approximation  

---

## 🔹 Inputs

- A function (implemented in C, e.g., sin(x), cos(x), x^2, etc.)  
- Point `a` for linearization  
- Value `x` near `a` to evaluate the approximation  

---

## 🔹 Outputs

- Linear approximation of `f(x)`  
- Actual value of `f(x)` for comparison  
- Error between approximation and actual value