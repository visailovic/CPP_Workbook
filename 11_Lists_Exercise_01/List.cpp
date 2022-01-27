#include "List.h"

List::~List()
{
    Clear();
}
void List::Clear()
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
}
int List::GetSize()
{
    int counter = 0;

    Node* pNode = head;
    while (pNode != NULL)
    {
        counter++;
        pNode = pNode->GetNext();
    }
    return counter;
}

void List::Print()
{
    Node* tmp = head;

    // No nodes
    if (tmp == NULL) {
        cout << "EMPTY" << endl;
        return;
    }

    // One node in the list
    if (tmp->GetNext() == NULL)
    {
        cout << tmp->GetData();
        cout << " --> ";
        cout << "NULL" << endl;
    }
    else
    {
        // Parse and print the list
        do {
            cout << tmp->GetData();
            cout << " --> ";
            tmp = tmp->GetNext();
        } while (tmp != NULL);

        cout << "NULL" << endl;
    }
}

void List::Append(int data)
{
    // Create a new node
    Node* newNode = new Node();
    newNode->SetData(data);
    newNode->SetNext(NULL);

    Node* tmp = head;

    if (tmp != NULL)
    {
        while (tmp->GetNext() != NULL)
        {
            tmp = tmp->GetNext();
        }
        tmp->SetNext(newNode);
    }
    else
    {
        head = newNode;
    }
}

void List::Remove(int index)
{
    Node* tmp = head;

    // No nodes
    if (tmp == NULL)
    {
        cout << "Empty list!" << endl;
        return;
    }
    else
    {
        if (index >= GetSize())
        {
            cout << "Error!" << endl;
        }
        else
        {
            Node* prev = NULL;
            int counter = 0;
            while (counter < index)
            {
                prev = tmp;
                tmp = tmp->GetNext();
                counter++;
            }

            if (prev == NULL)
            {
                head = tmp->GetNext();
                delete tmp;
            }
            else
            {
                prev->SetNext(tmp->GetNext());
                delete tmp;
            }
        }
    }
}

void List::Insert(int index, int value)
{
    if (index < 0 && index >= GetSize())
    {
        cout << "Error! Index is out of range!" << endl;
        return;
    }
    if (index == 0)
    {
        Node* pNewNode = new Node;
        pNewNode->SetData(value);
        pNewNode->SetNext(head);
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
        tmp->SetNext(pNewNode);
    }
}
