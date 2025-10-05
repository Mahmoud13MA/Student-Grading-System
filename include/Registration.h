#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <iostream>
#include <string>
using namespace std;

struct Registration {
    int studentID;
    int courseCode;
    Registration* next;
    Registration* prev;

    Registration(int sid, int ccode);
};

class RegistrationList {
private:
    Registration* head;

public:
    RegistrationList();
    ~RegistrationList();
    void addRegistration(int sid, int ccode);
    void showRegistrations();
};

#endif
