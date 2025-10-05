#include "../include/Course.h"

Course::Course(int c, string n) {
    code = c; name = n; left = right = nullptr;
}

CourseTree::CourseTree() { root = nullptr; }
CourseTree::~CourseTree() { freeTree(root); }

void CourseTree::freeTree(Course* node) {
    if (node) {
        freeTree(node->left);
        freeTree(node->right);
        delete node;
    }
}

void CourseTree::insert(Course*& node, int code, string name) {
    if (!node)
        node = new Course(code, name);
    else if (code < node->code)
        insert(node->left, code, name);
    else
        insert(node->right, code, name);
}

void CourseTree::addCourse(int code, string name) {
    insert(root, code, name);
}

void CourseTree::display(Course* node) {
    if (!node) return;
    display(node->left);
    cout << "Course Code: " << node->code << " | Name: " << node->name << endl;
    display(node->right);
}

void CourseTree::showCourses() {
    display(root);
}
