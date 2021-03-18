#pragma once

class Matrix
{
public:
    Matrix(void);
    Matrix(int rows, int cols);
    Matrix(const Matrix& other);
    ~Matrix(void);

private:
    int** m_pData;
    int m_NumOfCols;
    int m_NumOfRows;

    void Allocate(int rows, int cols);
    void Deallocate();
    void Copy(const Matrix& source);
    void Init();
public:
    int GetRowCount() const { return m_NumOfRows; }
    int GetColCount() const { return m_NumOfCols; }
    void Print();

    void SetSize(int row, int col);
    bool SetElem(int row, int col, int value);
    const Matrix& operator=(const Matrix& other);
    Matrix operator+(const Matrix& other);
    Matrix operator*(const Matrix& other);
};