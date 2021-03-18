#include <iostream>
using namespace std;

int* GetPositiveElements(int* array, int size, int* pSizeOfPositives)
{
    int* pAuxiliaryArray = new int[size];
    int postiveCounter = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] > 0)
        {
            *(pAuxiliaryArray + postiveCounter) = array[i];
            //     pAuxiliaryArray[postiveCounter] = *(array+i);
            postiveCounter++;
        }
    }

    int* pArrayOfPositives = new int[postiveCounter];
    for (int i = 0; i < postiveCounter; i++)
        pArrayOfPositives[i] = pAuxiliaryArray[i];

    delete[] pAuxiliaryArray;

    *pSizeOfPositives = postiveCounter;
    return pArrayOfPositives;
}

void PrintArray(int* pArray, int size)
{
    for (int i = 0; i < size; i++)   cout << *(pArray + i) << "   ";
}

int main()
{
    cout << "Enter the size of array: " << endl;
    int size = 0;
    cin >> size;

    int* pArray = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << endl << "Enter element No. " << i + 1 << endl;
        cin >> pArray[i];
    }

    int positiveCount = 0;
    int* pArrayOfPositives = GetPositiveElements(pArray, size, &positiveCount);

    PrintArray(pArrayOfPositives, positiveCount);

    delete[] pArray; delete[] pArrayOfPositives;
}
