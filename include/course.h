#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Course {
    int code;
    string name;
    Course* left;
    Course* right;

    Course(int c, string n);
};

class CourseTree {
private:
    Course* root;
    void insert(Course*& node, int code, string name);
    void display(Course* node);
    void freeTree(Course* node);

public:
    CourseTree();
    ~CourseTree();
    void addCourse(int code, string name);
    void showCourses();
};

#endif
