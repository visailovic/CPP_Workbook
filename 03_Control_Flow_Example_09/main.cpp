#include <iostream>
using namespace std;

int main()
{
    int N, number = 0;

    cout << "Number of readings (N):" << endl;
    cin >> N;

    int counter = 0;

    for (int i = 0; i < N; i++)
    {
        cout << "Enter the number " << i + 1 << endl;
        cin >> number;

        if (number % 2 == 0) continue;

        if (number % 3 == 0)
            counter++;
    }

    cout << "The number of odd numbers divisible by 3 is " << counter << endl;

    return 0;
}
