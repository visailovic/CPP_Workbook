#include <iostream>
#include <cmath>

int main()
{
    float a, b, c, s, p, o;
    int x;

    std::cout << "Enter triangle sides: " << std::endl;
    std::cin >> a >> b >> c;

    if ((a + b > c) && (a + c > b) && (b + c > a))
    {
        std::cout << "To calculate circumference, press 1" << std::endl
            << "To calculate area, press 2" << std::endl;
        std::cin >> x;
        if (x == 1)
        {
            o = a + b + c;
            std::cout << "Circumference of triangle is: " << o << std::endl;
        }
        if (x == 2)
        {
            s = (a + b + c) / 2;
            p = sqrt(s * (s - a) * (s - b) * (s - c));
            std::cout << "Area of triangle is " << p << std::endl;
        }
    }
    else
        std::cout << "Wrong values of sides!" << std::endl;
}
