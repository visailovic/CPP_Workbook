#include <iostream>
#include <cmath>

double min(double a, double b)
{
    if (a < b)
        return a;
    else
        return b;
}

double max(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    double a, b, z;
    std::cout << "Enter two floating point numbers: " << std::endl;
    std::cin >> a >> b;

    if (b < 0.0)
    {
        std::cout << "The number b has to be greater than zero!" << std::endl;
        return 0;
    }

    z = 2.0 * max(a, b) / (1.0 + min(pow(a, 2), sqrt(b)));
    std::cout << "a= " << a << " " << "b= " << b << " " << "z= " << z << std::endl;

    return 0;
}
