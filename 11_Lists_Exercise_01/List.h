#pragma once

#include <iostream>
#include "Node.h"
using namespace std;

class List
{
private:
    Node* head;
public:
    List() { head = NULL; };
    ~List();
    void Print();
    void Append(int data);
    void Remove(int index);
    void Insert(int index, int value);
    int GetSize();
    void Clear();
};