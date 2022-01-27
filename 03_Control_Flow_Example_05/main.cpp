#include <iostream>
using namespace std;

int main()
{
    int n;
    double ar1 = 0, ar2 = 0, nullCounter = 0;
    int numberOfPositive = 0, numberOfNegative = 0;

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter the number: " << endl;
        cin >> n;
        if (n > 0)
        {
            ar1 += n;
            numberOfPositive++;
        }
        if (n < 0)
        {
            ar2 += n;
            numberOfNegative++;
        }
        if (n == 0) nullCounter++;
    }

    cout << "Mean value of pozitive numbers is: " << ar1 / numberOfPositive << endl;
    cout << "Mean value of negative numbers is: " << ar2 / numberOfNegative << endl;
    cout << "Number of zeros: " << nullCounter << endl;

    return 0;
}
