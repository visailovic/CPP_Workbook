#include <iostream>
// #include <cmath>

int abs(int value)
{
    if (value >= 0)
        return value;
    else
        return (-value);
}

int main()
{
    int a, y;

    std::cout << "Enter some integer:" << std::endl;
    std::cin >> a;

    std::cout << "The absolute value of entered number is: " << abs(a) << std::endl;

    return 0;
}