#include <iostream>
#include "DoubleLinkedList.h"
int main()
{
    DoubleLinkedList list;
    list.Append(100);
    list.Append(200);
    list.Append(300);
    list.Append(400);
    list.Append(500);
    list.PrintLeftToRight();
    list.Insert(3, 350);

    list.PrintRightToLeft();
    list.PrintLeftToRight();

    list.Remove(5);
    list.Remove(0);

    list.PrintRightToLeft();
    list.PrintLeftToRight();

    list.Remove(2);

    list.PrintRightToLeft();
    list.PrintLeftToRight();
}
