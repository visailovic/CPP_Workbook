#include <iostream>
using namespace std;

struct Matrix
{
    int numOfRows;
    int numOfCols;

    int** data;
};

void AllocateMatrix(Matrix* pMatrix, int numOfRows, int numOfColumns)
{
    pMatrix->data = new int* [numOfRows];

    for (int i = 0; i < numOfRows; i++)
    {
        pMatrix->data[i] = new int[numOfColumns];
    }

    pMatrix->numOfCols = numOfColumns;
    pMatrix->numOfRows = numOfRows;
}

void DeallocateMatrix(Matrix* pMatrix)
{
    for (int i = 0; i < pMatrix->numOfRows; i++)
    {
        delete[] pMatrix->data[i];
    }
    delete[] pMatrix->data;

    pMatrix->numOfCols = 0;
    pMatrix->numOfRows = 0;
}

bool AddElemInMatrix(Matrix* matrix, int row, int col, int value)
{
    if (row < matrix->numOfRows && col < matrix->numOfCols)
    {
        matrix->data[row][col] = value;
        //    *(*(matrix->data+row)+col) = value;
        return true;
    }
    else
    {
        return false;
    }
}

int GetElemFromMatrix(Matrix* pMatrix, int row, int col)
{
    return *(*(pMatrix->data + row) + col);
}

void PrintMatrix(Matrix* pMatrix)
{
    cout << endl << endl;

    for (int i = 0; i < pMatrix->numOfRows; i++)
    {
        for (int j = 0; j < pMatrix->numOfCols; j++)
        {
            cout << GetElemFromMatrix(pMatrix, i, j) << "\t";
        }
        cout << endl;
    }

    cout << endl << endl;
}

int main()
{
    Matrix matrix;
    int numberOfColumns;
    int numberOfRows;

    cout << "Number of rows: " << endl;
    cin >> numberOfRows;
    cout << "Number of columns: " << endl;
    cin >> numberOfColumns;

    AllocateMatrix(&matrix, numberOfRows, numberOfColumns);

    int counter = 0;
    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            int valueToPutInMatrix = ++counter;
            AddElemInMatrix(&matrix, i, j, valueToPutInMatrix);
        }
    }

    PrintMatrix(&matrix);
    DeallocateMatrix(&matrix);
}
