#pragma once
class Figure
{
public:

    Figure()
    {
        X = 0;
        Y = 0;
    }
    Figure(double x, double y)
    {
        X = x;
        Y = y;
    }

protected:
    double X;
    double Y;
public:
    void Translate(double x, double y)
    {
        X += x;
        Y += y;
    };
    virtual void Print() = 0;
};
