# 🎓 Student Management System (C)

## 📌 Overview
This project is a console-based Student Management System developed in C.

It allows management of:
- Students
- Subjects
- Grades
- Academic performance

---

## 🎯 Objectives
- Practice C programming (structures, file I/O)
- Build a modular application
- Ensure data validation and consistency

---

## ⚙️ Features

### Student Management
- Add students
- Prevent duplicates
- Display student list

### Subject Management
- Add subjects
- Validate uniqueness
- Display subjects

### Grade Management
- Add, modify, delete grades
- Validate grades (0–20)

### Performance
- Calculate averages
- Generate report cards

---

## 🏗️ Architecture
- main.c → program entry
- etudiant.c → student logic
- matiere.c → subject logic
- note.c → grades
- mesfonctions.c → calculations
- CDS.c → validation
- code.c → UI

---

## 💾 Data Storage
Binary files:
- fetud.ing
- fmatiere.ing
- fnote.ing

---

## ▶️ How to Run

Compile:
gcc *.c -o student_system

Run:
./student_system

---

## 🚧 Limitations
- CLI only
- No database
- Single user

---

## 🔮 Future Work
- GUI
- Database integration
- Authentication

---

## 👤 Author
Alex Cabrel Tsapi Koudjou
