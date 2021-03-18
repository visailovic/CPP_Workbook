#include <iostream>
using namespace std;
#define ARRAY_SIZE 10

double Mean(int* array, int size)
{
    double average = 0.0;
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        if ((array[i] % 2) == 0)
        {
            average += array[i];
            counter++;
        }
    }
    return average / counter;
}

int main()
{
    cout << "Enter 10 integers:" << std::endl;
    int* array = new int[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) cin >> array[i];

    cout << "Array's mean value = " << Mean(array, ARRAY_SIZE) << std::endl;

    delete[] array;

    return 0;
}
