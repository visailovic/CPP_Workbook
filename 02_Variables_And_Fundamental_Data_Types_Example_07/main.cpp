#include <iostream>
#include <cmath>

int main()
{
    double x, y, z, v;
    double a, b, c, max;
    std::cout << ("Enter four floating point numbers: x, y, z, v") << std::endl;
    std::cin >> x >> y >> z >> v;
    a = abs(x - y);
    b = abs(y - z);
    c = abs(z - v);
    max = b;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    std::cout << "The diferences are: " << a << " " << b << " " << c << std::endl;
    std::cout << ("The largest difference is: ") << max << std::endl;

    return 0;
}
