#include <iostream>
using namespace std;

struct Vector
{
    double x;
    double y;
    double z;
};

Vector GetVector()
{
    Vector V;
    cout << "X component: " << endl;
    cin >> V.x;
    cout << "Y component: " << endl;
    cin >> V.y;
    cout << "Z component: " << endl;
    cin >> V.z;

    return V;
}

Vector AddVector(Vector vector1, Vector vector2)
{
    Vector res;

    res.x = vector1.x + vector2.x;
    res.y = vector1.y + vector2.y;
    res.z = vector1.z + vector2.z;

    return res;
}

void PrintVector(Vector V)
{
    cout << "(" << V.x << "," << V.y << "," << V.z << ")" << endl;
}

int main()
{
    Vector v1;
    Vector v2;

    cout << "Enter Components of vector 1: " << endl << endl;
    v1 = GetVector();
    cout << "Enter Components of vector 2: " << endl << endl;
    v2 = GetVector();

    Vector result = AddVector(v1, v2);
    cout << endl << "Components of result vector are: " << endl;

    PrintVector(result);
    return 0;
}
