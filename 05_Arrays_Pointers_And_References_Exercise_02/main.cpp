#include <iostream>
using namespace std;

void PrintMatrix(int* pMatrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(pMatrix + i) << endl;
    }
}

int main()
{
    const int row = 3;
    const int col = 5;
    int matrix[row][col] = { {5,4,3,2,1},
                    {6,7,8,9,10},
                    {15,14,13,12,11} };

    PrintMatrix((int*)matrix, row * col);
}
