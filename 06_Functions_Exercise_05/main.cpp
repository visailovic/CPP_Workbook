#include "math.h"

struct Point
{
    double X, Y;
};

struct LineSegment
{
    Point P1, P2;
};

struct PolyLine
{
    Point* points;
    int length;
};

void rotate(PolyLine& polyLine, double angle)
{
    for (int i = 0; i < polyLine.length; i++)
    {
        Point P = polyLine.points[i];
        double X = cos(angle) * P.X - sin(angle) * P.Y;
        double Y = sin(angle) * P.X + cos(angle) * P.Y;
        polyLine.points[i].X = X;
        polyLine.points[i].Y = Y;
    }
}

PolyLine makePolyLine(LineSegment lineSegments[], int length)
{
    PolyLine polyLine;
    polyLine.points = new Point[length + 1];
    polyLine.length = length + 1;
    polyLine.points[0] = lineSegments[0].P1;
    polyLine.points[1] = lineSegments[0].P2;
    for (int i = 1; i < length; i++)
    {
        Point V;
        V.X = polyLine.points[i].X - lineSegments[i].P1.X;
        V.Y = polyLine.points[i].Y - lineSegments[i].P1.Y;
        Point P = lineSegments[i].P2;
        P.X += V.X;
        P.Y += V.Y;
        polyLine.points[i + 1] = P;
    }
    return polyLine;
}

#define PI 4.0 * atan(1)

int main()
{
    LineSegment lineSegment[3] = { { {1,1},{2,2} }, { {1,1},{2,1} }, { {1,1},{1,2} } };

    PolyLine polyLine = makePolyLine(lineSegment, 3);

    rotate(polyLine, PI / 2);

    return 0;
}