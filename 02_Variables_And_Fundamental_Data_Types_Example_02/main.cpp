#include <iostream>

int main()
{
    int a, y;

    std::cout << "Enter some integer:" << std::endl;
    std::cin >> a;
    if (a >= 0)
        y = a;
    else
        y = -a;
    std::cout << "The absolute value of entered number is: " << y << std::endl;

    return 0;
}
