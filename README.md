# CodeAlpha_CGPA-Calculator
# C++ Academic GPA & CGPA Calculator 🎓

A console-based academic tracking utility built in C++. Designed for undergraduate students to accurately compute semester GPAs, track cumulative GPAs (CGPA), and evaluate degree classifications with built-in error handling and input validation.

## 🚀 Features

* **Struct-Based Data Management:** Organizes course details using structured data types (`Course`) storing titles, scores, credit hours, grade points, and letter grades.
* **Robust Input Validation:** Prevents program crashes from incorrect data types (e.g., typing letters instead of numbers) and enforces valid score/credit ranges.
* **Automated Grading & Classification:** Automatically maps percentage scores to standard letter grades (`A` to `F`) and assigns institutional grade points.
* **Semester & Cumulative Tracking:** Computes both the current term's GPA and the overall Cumulative GPA (CGPA) by integrating past academic records.
* **Degree Classification:** Evaluates final CGPA to determine academic standing (First Class, Second Class Upper, etc.).

## 🛠️ Tech Stack
* **Language:** C++
* **Key Libraries:** `<iostream>`, `<vector>`, `<iomanip>`, `<limits>`, `<string>`

## ⚙️ Getting Started & Compilation

To run this project locally, ensure you have a C++ compiler installed (like GCC/MinGW or Clang).
