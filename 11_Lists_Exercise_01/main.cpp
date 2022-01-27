#include <iostream>
#include "List.h"
int main()
{
    List list;
    list.Append(100);
    list.Append(200);
    list.Append(300);
    list.Append(400);
    list.Append(500);
    list.Print();

    list.Insert(3, 350);
    list.Print();

    list.Remove(1);
    list.Print();
}
