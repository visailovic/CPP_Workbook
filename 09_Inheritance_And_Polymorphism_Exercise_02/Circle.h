#pragma once
#include <iostream>
#include "Figure.h"
#include "math.h"
using namespace std;

class Circle : public Figure
{
protected:
    double radius;
public:
    Circle() : Figure() { radius = 0; }
    Circle(double x, double y, double r) : Figure(x, y)
    {
        radius = r;
    }
    ~Circle() {}
    void Print()
    {
        double PI = 4.0 * atan(1.0);

        cout << endl;
        cout << "Position of circle: (X,Y)" << endl;
        cout << "(" << X << ", " << Y << ")" << endl;
        cout << "Circumference: " << radius * 2 * PI << endl;
        cout << "Area: " << radius * radius * PI << endl;
        cout << endl;
    }
};
