#include <iostream>

double min(double a, double b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    double a, b, minimum, z;
    std::cout << "Enter two floating point numbers: " << std::endl;
    std::cin >> a >> b;
    minimum = min(a, b);

    if (a >= 0) z = minimum;
    else        z = 2 * minimum;
    std::cout << "a= " << a << " " << "b= " << b << " " <<
        "min= " << minimum << " " << "z= " << z << std::endl;
}
