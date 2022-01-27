#include <iostream>
#include "Matrix.h"

int main()
{
    Matrix M1(3, 2);
    Matrix M2(2,3);

    M1.SetElem(0, 0, 1);
    M1.SetElem(0, 1, 10);
    M1.SetElem(1, 0, 2);
    M1.SetElem(1, 1, 20);
    M1.SetElem(2, 0, 3);
    M1.SetElem(2, 1, 30);

    M2.SetElem(0, 0, 1);
    M2.SetElem(0, 1, 10);
    M2.SetElem(0, 2, 2);
    M2.SetElem(1, 0, 20);
    M2.SetElem(1, 1, 3);
    M2.SetElem(1, 2, 30);

    Matrix M3 = M1 * M2;
    Matrix M4 = M2 * M1;

    M3.Print();
    M4.Print();
}