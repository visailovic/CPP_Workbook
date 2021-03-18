#include "math.h"
#include <iostream>

using namespace std;

void Triangle(double cathetus1, double cathetus2, double& hypotenuse, double& angle1, double& angle2)
{
    hypotenuse = sqrt(cathetus1 * cathetus1 + cathetus2 * cathetus2);
    angle1 = acos(cathetus1 / hypotenuse);
    angle2 = acos(cathetus2 / hypotenuse);
}

int main()
{
    double c1 = 5.0;
    double c2 = 8.0;
    double h, angle1, angle2;

    Triangle(c1, c2, h, angle1, angle2);

    return 0;
}