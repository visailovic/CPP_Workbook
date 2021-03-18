#include <iostream>
#include <cmath>
#define PI 3.1415926535897932384626433832795
using namespace std;

enum TPolygonType
{
    PT_TRIANGLE = 3,
    PT_SQUARE = 4,
    PT_PENTAGON = 5,
    PT_HEXAGON = 6,
    PT_HEPTAGON = 7,
    PT_OCTAGON = 8
};

struct Point
{
    double x;
    double y;
};

typedef Point Vector;

struct Polygon
{
    Point points[8];
    TPolygonType polygonType;
};

Polygon GetPolygon(int numberOfCorners)
{
    Polygon polygon;
    polygon.polygonType = (TPolygonType)numberOfCorners;

    for (int i = 0; i < numberOfCorners; i++)
    {
        cout << "Enter the point No. " << i + 1 << "(X,Y)";
        cin >> polygon.points[i].x;
        cin >> polygon.points[i].y;
    }
    return polygon;
}

void PrintPolygon(Polygon poly)
{
    cout << "Polygon points:" << endl;
    for (int i = 0; i < (int)poly.polygonType; i++)
    {
        cout << "Point " << i + 1 << "\tX = " << poly.points[i].x <<
            "\tY = " << poly.points[i].y << endl;
    }
}

Point TranslatePoint(Point pointToTranslate, Vector vector)
{
    Point translatedPoint;

    translatedPoint.x = pointToTranslate.x + vector.x;
    translatedPoint.y = pointToTranslate.y + vector.y;

    return translatedPoint;
}

Point RotatePoint(Point pointToRotate, double angle)
{
    Point rotatedPoint;

    rotatedPoint.x = pointToRotate.x * cos(angle) - pointToRotate.y * sin(angle);
    rotatedPoint.y = pointToRotate.x * sin(angle) + pointToRotate.y * cos(angle);

    return rotatedPoint;
}

Polygon TranslatePolygon(Polygon polygonToTranslate, Vector translation)
{
    Polygon translatedPolygon;
    translatedPolygon.polygonType = polygonToTranslate.polygonType;

    for (int i = 0; i < (int)polygonToTranslate.polygonType; i++)
    {
        translatedPolygon.points[i] = TranslatePoint(polygonToTranslate.points[i], translation);
    }

    return translatedPolygon;
}

Polygon RotatePolygon(Polygon polygonToRotate, double angle)
{
    Polygon rotatedPolygon;
    rotatedPolygon.polygonType = polygonToRotate.polygonType;

    for (int i = 0; i < (int)polygonToRotate.polygonType; i++)
    {
        rotatedPolygon.points[i] = RotatePoint(polygonToRotate.points[i], angle);
    }

    return rotatedPolygon;
}

int main()
{
    int numberOfCorners = 0;
    cout << "Enter the number of corners:" << endl;
    cin >> numberOfCorners;

    cout << "Enter the polygon points:" << endl;
    Polygon poly;
    poly = GetPolygon(numberOfCorners);

    cout << "Enter translation vector (X, Y):";
    Vector translationVector;
    cin >> translationVector.x;
    cin >> translationVector.y;

    Polygon translatedPolygon = TranslatePolygon(poly, translationVector);

    PrintPolygon(translatedPolygon);

    double rotationAngle = 0.0;
    cout << "Enter rotation angle in degres:";
    cin >> rotationAngle;
    rotationAngle = rotationAngle * PI / 180.0; //Conversion degre to radian

    Polygon rotatedPolygon = RotatePolygon(poly, rotationAngle);

    PrintPolygon(rotatedPolygon);

    return 0;
}
