#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float grade;
    Student* next;

    Student(int i, string n, float g);
};

class StudentList {
private:
    Student* head;

public:
    StudentList();
    ~StudentList();
    void addStudent(int id, string name, float grade);
    void displayStudents();
    void removeStudent(int id);
    Student* findStudent(int id);
};

#endif
