#include <iostream>
#include <cmath>

int main()
{
    float a, y;

    std::cout << "Enter variable a:" << std::endl;
    std::cin >> a;

    if (a > 0)
        y = sqrt(a);
    else
        y = pow(a, 2);

    std::cout << y << std::endl;

    return 0;
}
