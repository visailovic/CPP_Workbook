#include <iostream>

using namespace std;
int main()
{
    int i, counter, n;
    cout << ("Enter 10 integers and check how many is divisible by 7") << endl;
    counter = 0;
    i = 1;
    while (i <= 10)
    {
        cout << i << " . number" << endl;
        cin >> n;
        if (n % 7 == 0)
            counter++;
        i++;
    }
    cout << ("By 7 is divisible: ") << counter << " number(s)" << endl;

    return 0;
}
