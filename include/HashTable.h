#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct HashNode {
    int key;
    string value;
    HashNode* next;

    HashNode(int k, string v);
};

class HashTable {
private:
    vector<HashNode*> table;
    int capacity;

    int hashFunction(int key) const;

public:
    HashTable(int size = 10);
    ~HashTable();

    void insert(int key, string value);
    string search(int key);
    void remove(int key);
    void display();
};

#endif
