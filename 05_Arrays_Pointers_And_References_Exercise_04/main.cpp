#include <cstdlib>
#include <iostream>

using namespace std;

int* GenerateRandomArray(int size, int** pointerToTheMin, int** pointerToTheMax)
{
    int* array = new int[size];

    for (int i = 0; i < size; i++) array[i] = rand();

    int indexOfMin = 0;
    int indexOfMax = 0;
    int min = array[0];
    int max = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            indexOfMin = i;
            min = array[i];
        }
        if (array[i] > max)
        {
            indexOfMax = i;
            max = array[i];
        }
    }
    *pointerToTheMin = &array[indexOfMin];
    *pointerToTheMax = &array[indexOfMax];

    return array;
}

int main()
{
    cout << "Enter the size of random value's array: ";
    int size = 0;
    cin >> size;

    int* pElemMax = 0;
    int* pElemMin = 0;

    int* randomValueArray = GenerateRandomArray(size, &pElemMin, &pElemMax);

    cout << *pElemMin << endl;
    cout << *pElemMax << endl;

    delete[] randomValueArray;

    return 0;
}
