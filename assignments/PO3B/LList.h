#pragma once
#include <iostream>
#include "fighterSub.cpp"
using namespace std;

class Node {
public:
    Node(BaseFighter d, Node* n, Node* n2);
    BaseFighter data;
    Node* next;
    Node* prev;
};

class LList {
public:
    LList();
    ~LList();
    void enqueue(BaseFighter val);
    bool dequeue();
    void print();
    //Node* getPrev(int key);

private:
    Node* front;
    Node* tail;
};
