#include "../include/Student.h"

Student::Student(int i, string n, float g) {
    id = i; name = n; grade = g; next = nullptr;
}

StudentList::StudentList() { head = nullptr; }

StudentList::~StudentList() {
    Student* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void StudentList::addStudent(int id, string name, float grade) {
    Student* newStudent = new Student(id, name, grade);
    newStudent->next = head;
    head = newStudent;
}

void StudentList::displayStudents() {
    Student* temp = head;
    while (temp) {
        cout << "ID: " << temp->id << " | Name: " << temp->name << " | Grade: " << temp->grade << endl;
        temp = temp->next;
    }
}

void StudentList::removeStudent(int id) {
    Student* temp = head;
    Student* prev = nullptr;

    while (temp && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Student not found\n";
        return;
    }

    if (!prev)
        head = head->next;
    else
        prev->next = temp->next;

    delete temp;
}

Student* StudentList::findStudent(int id) {
    Student* temp = head;
    while (temp) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}
