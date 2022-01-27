#pragma once

class DoubleArray
{
private:
    int m_length;
    double* m_data;

public:
    DoubleArray()
    {
        m_length = 0;
        m_data = 0;
    }

    DoubleArray(int length)
    {
        m_data = new double[length];
        m_length = length;
    }

    ~DoubleArray()
    {
        delete[] m_data;
    }

    void Erase()
    {
        delete[] m_data;
        m_data = 0;
        m_length = 0;
    }

    double& operator[](int index)
    {
        return m_data[index];
    }

    int getLength() { return m_length; }
};
