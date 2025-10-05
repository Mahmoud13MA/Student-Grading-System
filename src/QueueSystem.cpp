#include "../include/QueueSystem.h"

QueueNode::QueueNode(int i, string n) {
    id = i; name = n; next = nullptr;
}

QueueSystem::QueueSystem() {
    front = rear = nullptr;
}

QueueSystem::~QueueSystem() {
    while (front) dequeue();
}

void QueueSystem::enqueue(int id, string name) {
    QueueNode* temp = new QueueNode(id, name);
    if (!rear) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void QueueSystem::dequeue() {
    if (!front) return;
    QueueNode* temp = front;
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
}

void QueueSystem::display() {
    QueueNode* temp = front;
    while (temp) {
        cout << "ID: " << temp->id << " | Name: " << temp->name << endl;
        temp = temp->next;
    }
}
