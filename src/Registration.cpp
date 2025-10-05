#include "../include/Registration.h"

Registration::Registration(int sid, int ccode) {
    studentID = sid; courseCode = ccode;
    next = prev = nullptr;
}

RegistrationList::RegistrationList() { head = nullptr; }

RegistrationList::~RegistrationList() {
    Registration* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void RegistrationList::addRegistration(int sid, int ccode) {
    Registration* newReg = new Registration(sid, ccode);
    newReg->next = head;
    if (head) head->prev = newReg;
    head = newReg;
}

void RegistrationList::showRegistrations() {
    Registration* temp = head;
    while (temp) {
        cout << "Student ID: " << temp->studentID << " -> Course Code: " << temp->courseCode << endl;
        temp = temp->next;
    }
}
