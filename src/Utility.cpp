#include "../include/Utility.h"
#include <iostream>
using namespace std;

void demoSystem() {
    cout << "===== STUDENT GRADING SYSTEM DEMO =====\n";

    StudentList students;
    CourseTree courses;
    RegistrationList regs;
    QueueSystem queue;
    HashTable hash(10);

    students.addStudent(1, "Ali", 88.5);
    students.addStudent(2, "Sara", 91.2);
    students.addStudent(3, "Omar", 77.9);

    courses.addCourse(101, "Math");
    courses.addCourse(102, "Physics");

    regs.addRegistration(1, 101);
    regs.addRegistration(2, 102);

    queue.enqueue(1, "Ali");
    queue.enqueue(2, "Sara");

    hash.insert(1, "Ali");
    hash.insert(2, "Sara");

    cout << "\n-- Students --\n"; students.displayStudents();
    cout << "\n-- Courses --\n"; courses.showCourses();
    cout << "\n-- Registrations --\n"; regs.showRegistrations();
    cout << "\n-- Queue --\n"; queue.display();
    cout << "\n-- Hash Table --\n"; hash.display();

    cout << "\nSearch ID 2 in HashTable: " << hash.search(2) << endl;
}
