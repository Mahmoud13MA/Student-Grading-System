#include "../include/HashTable.h"

HashNode::HashNode(int k, string v) {
    key = k;
    value = v;
    next = nullptr;
}

HashTable::HashTable(int size) {
    capacity = size;
    table.resize(size, nullptr);
}

HashTable::~HashTable() {
    for (int i = 0; i < capacity; i++) {
        HashNode* current = table[i];
        while (current) {
            HashNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
}

int HashTable::hashFunction(int key) const {
    return key % capacity;
}

void HashTable::insert(int key, string value) {
    int index = hashFunction(key);
    HashNode* newNode = new HashNode(key, value);
    if (!table[index]) {
        table[index] = newNode;
    } else {
        HashNode* temp = table[index];
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

string HashTable::search(int key) {
    int index = hashFunction(key);
    HashNode* temp = table[index];
    while (temp) {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return "Not Found";
}

void HashTable::remove(int key) {
    int index = hashFunction(key);
    HashNode* temp = table[index];
    HashNode* prev = nullptr;
    while (temp) {
        if (temp->key == key) {
            if (prev) prev->next = temp->next;
            else table[index] = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void HashTable::display() {
    for (int i = 0; i < capacity; i++) {
        cout << "[" << i << "]: ";
        HashNode* temp = table[i];
        while (temp) {
            cout << "(" << temp->key << "," << temp->value << ")";
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
}
