#include <iostream>
#include "Triangle.h"

using namespace std;

int main()
{
    cout << "Enter the number of triangles:" << endl;
    int numOfTriangles = 0;
    cin >> numOfTriangles;

    if (numOfTriangles < 1)
    {
        cout << "You have to enter at least one triangle!";
        return 0;
    }

    Triangle* pTriangles = new Triangle[numOfTriangles];

    int counter = 0;
    while (counter < numOfTriangles)
    {
        cout << "Enter the triangle number: " << counter + 1 << endl;
        ImportTriangle(*(pTriangles + counter));
        bool bCorrectTriangle = CheckTriangleEdges(pTriangles + counter);

        if (bCorrectTriangle)
        {
            counter++;
        }
    }

    if (pTriangles) delete[] pTriangles;
}
