#pragma once

#include <iostream>
using namespace std;

// Node class
class Node
{
    int data;
    Node* next;
    Node* prev;

public:
    Node() { data = 0; next = NULL; prev = NULL; };
    void SetData(int value) { data = value; };
    int GetData() { return data; };
    void SetNext(Node* pNext) { next = pNext; };
    Node* GetNext() { return next; };
    void SetPrev(Node* pPrev) { prev = pPrev; };
    Node* GetPrev() { return prev; };
};
