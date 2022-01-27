#pragma once

#include <iostream>
using namespace std;

// Node class
class Node
{
    int data;
    Node* next;

public:
    Node() {};
    void SetData(int nData) { data = nData; };
    int GetData() { return data; };
    void SetNext(Node* pNext) { next = pNext; };
    Node* GetNext() { return next; };
};
