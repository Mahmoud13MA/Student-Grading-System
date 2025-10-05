#ifndef QUEUESYSTEM_H
#define QUEUESYSTEM_H

#include <iostream>
#include <string>
using namespace std;

struct QueueNode {
    int id;
    string name;
    QueueNode* next;

    QueueNode(int i, string n);
};

class QueueSystem {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    QueueSystem();
    ~QueueSystem();
    void enqueue(int id, string name);
    void dequeue();
    void display();
};

#endif
