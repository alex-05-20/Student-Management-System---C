# 🎓 Student Management System (C)

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue">
  <img src="https://img.shields.io/badge/Application-Console-green">
  <img src="https://img.shields.io/badge/Architecture-Modular-orange">
  <img src="https://img.shields.io/badge/Focus-File%20Handling-critical">
</p>

---

## 📌 Overview

This project is a **console-based Student Management System** developed in C.

It allows users to manage academic data such as:
- 👨‍🎓 Students
- 📚 Subjects
- 📝 Grades
- 📊 Academic performance

The application follows a **modular architecture** and uses **file handling** to store data persistently.

---

## 🎯 Objectives

- Apply core **C programming concepts**
- Practice **structures and file handling**
- Build a **modular application**
- Ensure **data validation and consistency**
- Simulate a real academic management workflow

---

## 🚀 Features

### 👨‍🎓 Student Management
- Add student records
- Prevent duplicate students
- Display student list

### 📚 Subject Management
- Add subjects
- Validate unique subject codes
- Display subject list

### 📝 Grade Management
- Add grades
- Modify grades
- Delete grades
- Validate grades between 0 and 20

### 📊 Performance Analysis
- Calculate student averages
- Generate report cards
- Compute class averages

### 🛡️ Data Validation
- Validate user input
- Check duplicate records
- Verify file integrity

---

## 🏗️ Project Architecture

| File | Role |
|---|---|
| `main.c` | Main program and menu navigation |
| `etudiant.c / etudiant.h` | Student management |
| `matiere.c / matiere.h` | Subject management |
| `note.c / note.h` | Grade management |
| `mesfonctions.c` | Averages, reports, utility functions |
| `CDS.c` | Input validation |
| `code.c` | Console UI, colors, layout |

---

## 📂 Project Structure

project/
├── main.c
├── etudiant.c
├── etudiant.h
├── matiere.c
├── matiere.h
├── note.c
├── note.h
├── mesfonctions.c
├── CDS.c
├── code.c
└── README.md

---

## 💾 Data Storage

The system stores data using binary files:

| File | Content |
|---|---|
| `fetud.ing` | Student records |
| `fmatiere.ing` | Subject records |
| `fnote.ing` | Grade records |

The program uses `fread()` and `fwrite()` to persist data between sessions.

---

## ▶️ How to Run

### Compile
gcc *.c -o student_system

### Run
./student_system

On Windows:
student_system.exe

---

## 🎨 User Interface

- Console-based interface  
- Menu-driven navigation  
- ASCII layout  
- Colored text for better readability  

---

## 🔍 Design Highlights

- Modular architecture  
- Separation of concerns  
- File-based persistence  
- Input validation  
- Duplicate prevention  
- Structured academic reporting  

---

## 🚧 Limitations

- Console application only  
- No database integration  
- No authentication system  
- Single-user usage  
- Limited scalability due to file-based storage  

---

## 🔮 Future Improvements

- Add a graphical interface  
- Integrate SQLite or MySQL  
- Add user authentication  
- Support multiple semesters  
- Export reports as PDF or CSV  
- Add analytics dashboards  

---

## 💡 Key Takeaways

This project demonstrates:
- Solid C programming fundamentals  
- Practical use of structures and files  
- Ability to build a complete modular application  
- Understanding of validation and data consistency  

---

## 👤 Author

**Alex Cabrel Tsapi Koudjou**
