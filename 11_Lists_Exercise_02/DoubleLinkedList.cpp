#include "DoubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

DoubleLinkedList::~DoubleLinkedList()
{
    Clear();
}

void DoubleLinkedList::Clear()
{
    Node* tmp = head;
    while (tmp && tmp->GetNext())
    {
        Node* prev = tmp;
        tmp = tmp->GetNext();
        delete prev;
    }
    delete tmp;
    head = NULL;
    tail = NULL;
    size = 0;
}
void DoubleLinkedList::PrintLeftToRight()
{
    if (head == NULL)
    {
        printf("Empty List!! \n");
        return;
    }
    Node* temp = head;

    int counter = 0;
    while (temp != NULL)
    {
        cout << "Index: " << counter++ << "  :  " << temp->GetData() << endl;
        temp = temp->GetNext();
    }
    cout << endl;
}

void DoubleLinkedList::PrintRightToLeft()
{
    if (head == NULL)
    {
        printf("Empty List!! \n");
        return;
    }
    Node* temp = tail;

    int counter = size;
    while (temp != NULL)
    {
        cout << "Index: " << --counter << "  :  " << temp->GetData() << endl;
        temp = temp->GetPrev();
    }
    cout << endl;
}

void DoubleLinkedList::Append(int newElement)
{
    // Create a new node
    Node* newNode = new Node();
    newNode->SetData(newElement);

    Node* tmp = head;

    if (tmp != NULL)
    {
        while (tmp->GetNext() != NULL)
        {
            tmp = tmp->GetNext();
        }
        newNode->SetPrev(tmp);
        tmp->SetNext(newNode);
    }
    else
    {
        head = newNode;
    }
    tail = newNode;
    size++;
}

void DoubleLinkedList::Remove(int index)
{
    Node* tmp = head;

    // No nodes
    if (tmp == NULL)
    {
        cout << "Empty list!!! Cannot remove anything from empty list!" << endl;
        return;
    }
    else
    {
        if (index >= size)
        {
            cout << "Error!" << endl;
        }
        else
        {
            int counter = 0;
            while (counter < index)
            {
                tmp = tmp->GetNext();
                counter++;
            }

            if (tmp->GetPrev() != NULL)
                tmp->GetPrev()->SetNext(tmp->GetNext());
            else
                head = tmp->GetNext();

            if (tmp->GetNext() != NULL)
                tmp->GetNext()->SetPrev(tmp->GetPrev());
            else
                tail = tmp->GetPrev();

            delete tmp;
            size--;
        }
    }
}

void DoubleLinkedList::Insert(int index, int value)
{
    if (index < 0 && index >= size)
    {
        cout << "Error! Index is out of range!" << endl;
        return;
    }
    if (index == 0)
    {
        Node* pNewNode = new Node;
        pNewNode->SetData(value);
        pNewNode->SetNext(head);
        pNewNode->SetPrev(NULL);
        head->SetPrev(pNewNode);
        head = pNewNode;
    }
    else
    {
        Node* tmp = head;
        int i = 1;
        while (i < index)
        {
            i++;
            tmp = tmp->GetNext();
        }
        Node* pNewNode = new Node;

        pNewNode->SetData(value);

        pNewNode->SetNext(tmp->GetNext());
        pNewNode->SetPrev(tmp);

        pNewNode->GetNext()->SetPrev(pNewNode);
        pNewNode->GetPrev()->SetNext(pNewNode);
    }
    size++;
}
