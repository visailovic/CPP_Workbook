#include <iostream>
#include "Matrix.h"

int main()
{
    Matrix M1(2, 2);
    Matrix M2;

    M1.SetElem(0, 0, 1);
    M1.SetElem(0, 1, 10);
    M1.SetElem(1, 0, 2);
    M1.SetElem(1, 1, 20);

    M2 = M1;
    Matrix M3 = M1 + M2;

    M1.Print();
    M2.Print();
    M3.Print();
}