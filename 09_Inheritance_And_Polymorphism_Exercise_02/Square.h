#pragma once
#include <iostream>
#include "Figure.h"
using namespace std;

class Square : public Figure
{
protected:
    double side;
public:
    Square() : Figure() { side = 0; }
    Square(double x, double y, double a) : Figure(x, y)
    {
        side = a;
    }
    ~Square() {}
    void Print()
    {
        cout << endl;
        cout << "Position of square: (X,Y)" << endl;
        cout << "(" << X << ", " << Y << ")" << endl;
        cout << "Position of first corner: (X,Y)" << endl;
        cout << "(" << X - side / 2 << ", " << Y - side / 2 << endl;
        cout << "Position of second corner: (X,Y)" << endl;
        cout << "(" << X + side / 2 << ", " << Y - side / 2 << endl;
        cout << "Position of third corner: (X,Y)" << endl;
        cout << "(" << X - side / 2 << ", " << Y + side / 2 << endl;
        cout << "Position of fourth corner: (X,Y)" << endl;
        cout << "(" << X + side / 2 << ", " << Y + side / 2 << endl;
        cout << "Circumference: " << side * 4 << endl;
        cout << "Area: " << side * side << endl;
        cout << endl;
    }
};