#pragma once
#include <iostream>
#include "Figure.h"
using namespace std;

class Rectangle : public Figure
{
protected:
    double sideA;
    double sideB;
public:
    Rectangle() : Figure()
    {
        sideA = 0;
        sideB = 0;
    }
    Rectangle(double x, double y, double a, double b) : Figure(x, y)
    {
        sideA = a;
        sideB = b;
    }
    ~Rectangle() {}

    void Print()
    {
        cout << endl;
        cout << "Position of rectangle: (X,Y)" << endl;
        cout << "(" << X << ", " << Y << ")" << endl;

        cout << "Position of first corner: (X,Y)" << endl;
        cout << "(" << X - sideA / 2 << ", " << Y - sideB / 2 << endl;
        cout << "Position of second corner: (X,Y)" << endl;
        cout << "(" << X + sideA / 2 << ", " << Y - sideB / 2 << endl;
        cout << "Position of third corner: (X,Y)" << endl;
        cout << "(" << X - sideA / 2 << ", " << Y + sideB / 2 << endl;
        cout << "Position of fourth corner: (X,Y)" << endl;
        cout << "(" << X + sideA / 2 << ", " << Y + sideB / 2 << endl;

        cout << "Circumference: " << sideA * 2 + sideB * 2 << endl;
        cout << "Area: " << sideA * sideB << endl;
        cout << endl;
    }
};