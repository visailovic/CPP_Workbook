#include <iostream>
using namespace std;
int main()
{
    double number, sum = 0.0;

    cout << "The program calculates sum of floating point numbers." << endl;
    cout << "Numbers are entered successively until 0 is entered." << endl;

    while (1)
    {
        cout << "Enter a number: ";
        cin >> number;

        if (number == 0) break;

        sum += number;
    }

    cout << "Sum = " << sum << endl;

    return 0;
}
