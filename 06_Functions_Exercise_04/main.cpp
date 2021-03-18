#include <iostream>
#include <math.h>
using namespace std;

struct Point
{
    double X, Y;
};

struct Polygon
{
    Point* niz;
    int length;
};

void allocate(Polygon& P, int numberOfPoints)
{
    P.niz = new Point[numberOfPoints];
    P.length = numberOfPoints;
}

void deallocate(Polygon& P)
{
    delete[] P.niz;
    P.length = 0;
}

void importPoints(Polygon* P)
{
    for (int i = 0; i < P->length; i++)
    {
        cout << "Enter X and Y coordinate of point " << i + 1 << endl;
        cin >> P->niz[i].X >> P->niz[i].Y;
    }
}

double length(Polygon P)
{
    double length = 0.0;
    for (int i = 0; i < P.length; i++)
    {
        double segment = sqrt(pow(P.niz[i].X - P.niz[(i + 1) % P.length].X, 2) +
            pow(P.niz[i].Y - P.niz[(i + 1) % P.length].Y, 2));
        //	Second option
        //	int index1 = i, index2 = i + 1;
        //	if(index2 == length) index2 = 0;
        //	double segment = sqrt(pow(P.niz[index1].X - P.niz[index2].X, 2) +
        //				pow(P.niz[index1].Y - P.niz[index2].Y, 2));
        length += segment;
    }
    return length;
}

int main()
{
    Polygon P;

    cout << "Enter the number of points:" << endl;

    int numberOfPoints = 0;
    cin >> numberOfPoints;

    allocate(P, numberOfPoints);
    importPoints(&P);

    cout << "Circumference of polygon = " << length(P) << endl;
}