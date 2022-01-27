#pragma once

#include <iostream>

using namespace std;

struct Triangle
{
    double a;
    double b;
    double c;
};

int ImportTriangle(Triangle& triangle)
{
    cout << "Enter first edge:" << endl;
    cin >> triangle.a;
    cout << "Enter second edge:" << endl;
    cin >> triangle.b;
    cout << "Enter third edge:" << endl;
    cin >> triangle.c;

    return 0;
}

bool CheckTriangleEdges(Triangle* pTriangle)
{
    bool returnValue = (pTriangle->a > 0 && pTriangle->b > 0 && pTriangle->c > 0 &&
        ((pTriangle->a + pTriangle->b) > pTriangle->c) &&
        ((pTriangle->b + pTriangle->c) > pTriangle->a) &&
        ((pTriangle->c + pTriangle->a) > pTriangle->b));

    return returnValue;
}
