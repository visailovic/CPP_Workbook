#pragma once

class IntArray
{
private:
    int m_length;
    int* m_data;

public:
    IntArray()
    {
        m_length = 0;
        m_data = 0;
    }

    IntArray(int length)
    {
        m_data = new int[length];
        m_length = length;
    }

    ~IntArray()
    {
        delete[] m_data;
    }

    void Erase()
    {
        delete[] m_data;
        m_data = 0;
        m_length = 0;
    }

    int& operator[](int index)
    {
        return m_data[index];
    }

    int getLength() { return m_length; }
};
