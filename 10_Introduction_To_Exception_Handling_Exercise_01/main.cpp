#include "Array.h"

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    Array a(size);

    cout << "Enter the number of variables that you want to put in array: ";
    int numberOfVariables;
    cin >> numberOfVariables;

    for (int i = 0; i < numberOfVariables; i++)
    {
        int index;
        cout << "Enter the index where you want to put value: ";
        cin >> index;

        int value;
        cout << "Enter the value: ";
        cin >> value;

        try
        {
            a.SetValueAt(index, value);
        }
        catch (Array::Error& errorCode)
        {
            cout << errorMessages[errorCode];
        }
    }

    for (int i = 0; i < a.GetSize(); i++)
    {
        cout << "Element : " << i << " = " << a[i] << endl;
    }

    return 0;
}