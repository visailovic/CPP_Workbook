#include <iostream>
using namespace std;
int main()
{
    double number, sum = 0.0;

    cout << "The program calculates sum of floating point numbers." << endl;
    cout << "Numbers are entered successively until 0 is entered." << endl;

    do
    {
        cout << "Enter a number: ";
        cin >> number;

        sum += number;
    } while (number != 0);

    cout << "Sum = " << sum << endl;

    return 0;
}
