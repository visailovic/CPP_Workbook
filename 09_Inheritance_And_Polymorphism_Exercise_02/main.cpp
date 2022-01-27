#pragma once
#include <iostream>
#include "Figure.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
using namespace std;

void Print(Figure* array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        Figure* figure = array[i];
        figure->Print();
    }
}

void Translate(Figure* array[], int size, double x, double y)
{
    for (int i = 0; i < size; i++) array[i]->Translate(x, y);
}

int main()
{
    Figure* array[5];
    int size = 5;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the figure " << i + 1 << "/" << 5 << endl;
        cout << "Enter position of figure" << endl;
        double x, y;
        cin >> x >> y;

        cout << "Type of figure:  (C) - Circle, (S) - Square, (R) - Rectangle";
        cout << endl;
        char nType;
        cin >> nType;
        nType = toupper(nType);

        switch (nType)
        {
        case 'C':
            cout << "Enter the radius of circle:" << endl;
            double radius;
            cin >> radius;
            array[i] = new Circle(x, y, radius);
            break;
        case 'S':
            cout << "Enter the side of square:" << endl;
            double side;
            cin >> side;
            array[i] = new Square(x, y, side);
            break;
        case 'R':
            cout << "Enter the sides of rectangle:" << endl;
            double sideA, sideB;
            cin >> sideA >> sideB;
            array[i] = new Rectangle(x, y, sideA, sideB);
            break;
        default:
            cout << "Wrong input. Enter again...";
            i--;
            continue;
        }
    }

    cout << endl;
    cout << "Enter the translation vector: (X,Y)" << endl;
    double trX, trY;
    cin >> trX >> trY;

    Translate(array, size, trX, trY);

    Print(array, size);

    for (int i = 0; i < size; i++)
    {
        delete array[i];
    }
}
