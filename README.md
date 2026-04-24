# 🎓 Student Management System (C)
🎓 Student Management System (C)
<p align="center"> <img src="https://img.shields.io/badge/Language-C-blue"> <img src="https://img.shields.io/badge/Type-Console%20Application-green"> <img src="https://img.shields.io/badge/Focus-File%20Handling-orange"> <img src="https://img.shields.io/badge/Level-Intermediate-critical"> </p>
📌 Overview

This project is a console-based Student Management System developed in C.

It enables efficient management of:

👨‍🎓 Students
📚 Subjects
📝 Grades
📊 Academic performance

The system is designed with a modular architecture, strong data validation, and file-based persistence, simulating a real academic management workflow.

🎯 Key Objectives
Apply core concepts of C programming
Build a modular and maintainable system
Ensure data integrity and validation
Simulate a real-world academic management system
🚀 Features
👨‍🎓 Student Management
Add new students
Prevent duplicate entries
Display student records
📚 Subject Management
Add subjects with unique codes
Validate input data
Display subject list
📝 Grade Management
Add, modify, delete grades
Validate grades (0–20 range)
Link grades to students and subjects
📊 Performance Analysis
Calculate student averages
Generate report cards
Compute class averages
🛡️ Data Validation
Input validation (numbers, ranges, formats)
Duplicate detection
File integrity checks
🏗️ Architecture

The project follows a modular design, improving readability and maintainability:

Module	Description
main.c	Program entry & menu navigation
etudiant.c	Student management
matiere.c	Subject management
note.c	Grade management
mesfonctions.c	Calculations & reporting
CDS.c	Input validation
code.c	UI (colors, layout, navigation)
📂 Project Structure
/project
│── main.c
│── etudiant.c / etudiant.h
│── matiere.c / matiere.h
│── note.c / note.h
│── mesfonctions.c
│── CDS.c
│── code.c
│── README.md
💾 Data Storage

The system uses binary files for persistence:

File	Description
fetud.ing	Students data
fmatiere.ing	Subjects data
fnote.ing	Grades data

✔ Uses fread() / fwrite()
✔ Ensures data persistence between sessions

▶️ How to Run
1. Compile
gcc *.c -o student_system
2. Execute
./student_system
3. Use the Application
Navigate using arrow keys
Press Enter to select options
🎨 User Interface
Console-based UI
ASCII graphics
Colored text
Interactive menu navigation
🔍 Design Highlights
✔ Modular architecture (separation of concerns)
✔ Strong input validation layer
✔ File-based persistence system
✔ Clean and structured codebase
🚧 Limitations
CLI (no graphical interface)
File-based storage (not scalable)
No multi-user support
No authentication system
🔮 Future Improvements
GUI version (Qt / GTK)
Database integration (SQLite / MySQL)
User authentication
Multi-semester support
Analytics dashboard
🎥 Demo

📺 https://youtu.be/xpaOmDGxRm4

💡 Key Takeaways

This project demonstrates:

Strong C programming fundamentals
Practical use of file handling & structures
Ability to build a complete system from scratch
Understanding of software architecture & validation
👤 Author

Alex Cabrel Tsapi Koudjou
