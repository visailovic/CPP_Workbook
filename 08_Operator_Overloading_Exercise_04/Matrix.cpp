#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix(void)
{
    Init();
}

Matrix::Matrix(int rows, int cols)
{
    Init();
    Allocate(rows, cols);
}

Matrix::Matrix(const Matrix& other)
{
    Init();
    *this = other;
}

Matrix::~Matrix(void)
{
    Deallocate();
}

void Matrix::Init()
{
    m_pData = 0;
    m_NumOfRows = 0;
    m_NumOfCols = 0;
}

void Matrix::Allocate(int rows, int cols)
{
    if (m_pData)
    {
        return;
    }
    m_pData = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        m_pData[i] = new int[cols];
    }
    m_NumOfCols = cols;
    m_NumOfRows = rows;
}

void Matrix::Deallocate()
{
    if (!m_pData) return;
    for (int i = 0; i < m_NumOfRows; i++)
    {
        delete[] m_pData[i];
    }
    delete[] m_pData;
    Init();
}

void Matrix::SetSize(int rows, int cols)
{
    Deallocate();
    Allocate(rows, cols);
}

bool Matrix::SetElem(int row, int col, int value)
{
    if (row < m_NumOfRows && col < m_NumOfCols)
    {
        m_pData[row][col] = value;
        //    *(*(m_pData+row)+col) = value;
        return true;
    }
    else
    {
        return false;
    }
}

void Matrix::Copy(const Matrix& source)
{
    Deallocate();
    Allocate(source.GetRowCount(), source.GetColCount());

    for (int i = 0; i < m_NumOfRows; i++)
        for (int j = 0; j < m_NumOfCols; j++)
            m_pData[i][j] = source.m_pData[i][j];
}

const Matrix& Matrix::operator=(const Matrix& other)
{
    Copy(other);
    return *this;
}

Matrix Matrix::operator+(const Matrix& other)
{
    Matrix sum;

    if (m_NumOfCols == other.m_NumOfCols && m_NumOfRows == other.m_NumOfRows)
    {
        sum.SetSize(m_NumOfRows, m_NumOfCols);
        for (int i = 0; i < m_NumOfRows; i++)
            for (int j = 0; j < m_NumOfCols; j++)
                sum.SetElem(i, j, m_pData[i][j] + other.m_pData[i][j]);
    }
    return sum;
}

void Matrix::Print()
{
    cout << endl;
    cout << "Elements of matrix:" << endl;
    for (int i = 0; i < m_NumOfRows; i++)
    {
        for (int j = 0; j < m_NumOfCols; j++)
            cout << m_pData[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

Matrix Matrix::operator*(const Matrix& other)
{
    Matrix sum;

    if (m_NumOfCols == other.m_NumOfRows)
    {
        sum.SetSize(m_NumOfRows, other.m_NumOfCols);

        for (int i = 0; i < sum.m_NumOfRows; i++)
        {
            for (int j = 0; j < sum.m_NumOfCols; j++)
            {
                int value = 0.0;
                for (int k = 0; k < m_NumOfCols; k++)
                {
                    value += m_pData[i][k] * other.m_pData[k][j];
                }
                sum.SetElem(i, j, value);
            }
        }
    }
    return sum;
}