#include <iostream>
using namespace std;

int main()
{
    int mark;
    cout << "Grade" << endl;
    cout << "Grade (from 1 to 5)" << endl;
    cin >> mark;
    switch (mark)
    {
    case 1:
        cout << "Insufficient" << endl;
        cout << endl;
        break;
    case 2:
        cout << "Sufficient" << endl;
        cout << endl;
        break;
    case 3:
        cout << "Good" << endl;
        cout << endl;
        break;
    case 4:
        cout << "Very good" << endl;
        cout << endl;
        break;
    case 5:
        cout << "Excellent" << endl;
        cout << endl;
        break;
    }

    return 0;
}
