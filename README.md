# Student, Course and Grade Management System

A console application written in C/C++ that lets you register students, courses
and grades, and generate academic reports. 

**Authors:** Otávio de Lima Guinossi Amaral Gurgel and Guilherme de Lima Silva

## Features

- **Students:** create, delete, update and search (by student ID)
- **Courses:** create, delete, update and search (by course code)
- **Grades:** create, delete, update and search (by student ID and course)
- **Reports:**
  - Students failing two or more courses;
  - Students by first letter of their name;
  - Courses containing a given search term;
  - Courses with an average below 6.0;
  - Full student record sheet.
- **Test data:** a menu option that fills the system with sample data

## Requirements

- Dev-C++ or Code::Blocks;
- The `conio.h` and `conio2.h` libraries installed.

## Getting Started

1. Clone the repository: `git clone https://github.com/O-Gurgel/CRUD-C-CPP.git
2. Open the `.cpp` file in Dev-C++ or Code::Blocks
3. Build and run (F11 in Dev-C++)

## Usage

The main menu offers: Students, Courses, Grades, Reports and Test Data.
Press `ESC` to exit the program and `ENTER` to go back from a submenu.
To try the system quickly, use the Test Data option before opening the reports.

## Business Rules

- The student ID (RA) has at most 12 characters and must be unique
- The course code must be unique
- Grades range from 0 to 10; a grade of 6 or higher means approved
- A student can have only one grade per course
- Deleting a student or a course also deletes the related grades
- Each table holds a maximum of 100 records

## Code Structure

The project uses structs (`_alunos`, `_disciplinas`, `_notas`), static arrays
and functions organized by module (searches, CRUD operations, reports).

## Known Limitations

- Depends on `conio2.h`, so it runs on Windows only
- Data is stored in memory and is lost when the program closes

## Authors

- Otávio de Lima Guinossi Amaral Gurgel
- Guilherme de Lima Silva
