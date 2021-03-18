#pragma once

#include "Node.h"

class DoubleLinkedList
{
private:
    Node* head;
    Node* tail;
    int size;
public:
    DoubleLinkedList();
    virtual ~DoubleLinkedList();
    void Append(int newElement);
    void Insert(int index, int value);
    void Remove(int index);
    void PrintLeftToRight();
    void PrintRightToLeft();
    void Clear();
};
