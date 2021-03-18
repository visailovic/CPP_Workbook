#include <math.h>

#define PI 4.0 * atan(1.0)
//#define PI 3.1415926535897932384626433832795

class Figure
{
public:
    virtual double Area() = 0;
    virtual double Circumference() = 0;
    virtual bool operator > (Figure& f)
    {
        return Area() > f.Area();
    }
};

class Triangle : public Figure
{
private:
    double sideA;
    double sideB;
    double sideC;

public:
    Triangle()
    {
        sideA = 1.0;
        sideB = 1.0;
        sideC = 1.0;
    }

    Triangle(double a, double b, double c)
    {
        sideA = a;
        sideB = b;
        sideC = c;
    }

    double Area()
    {
        double s = (sideA + sideB + sideC) / 2;
        double area = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
        return area;
    }

    double Circumference()
    {
        return sideA + sideB + sideC;
    }
};

class Square : public Figure
{
private:
    double side;

public:
    Square()
    {
        side = 1.0;
    }

    Square(double a)
    {
        side = a;
    }
    virtual double Area()
    {
        return side * side;
    }

    virtual double Circumference()
    {
        return 4.0 * side;
    }
};

class Circle : public Figure
{
private:
    double radius;

public:
    Circle()
    {
        radius = 1.0;
    }

    Circle(double r)
    {
        radius = r;
    }
    virtual double Area()
    {
        return pow(radius, 2.0) * PI;
    }

    virtual double Circumference()
    {
        return 2.0 * radius * PI;
    }
};

int main()
{
    Triangle t;
    Square s;

    bool b1 = s > t;

    Figure& f1 = t;
    Figure& f2 = s;

    bool b2 = t > s;

    Figure* pFigure1 = new Square(2.0);
    Figure* pFigure2 = new Circle(5.0);

    bool b3 = *pFigure1 > *pFigure2;
    delete pFigure1;
    delete pFigure2;
}
