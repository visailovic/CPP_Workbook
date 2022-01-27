#pragma once
template <class T> // Template class, the user will provide the data type for T
class Array
{
private:
    int m_length;
    T* m_data;

public:
    Array()
    {
        m_length = 0;
        m_data = nullptr;
    }
    Array(int length)
    {
        m_data = new T[length];
        m_length = length;
    }
    ~Array()
    {
        delete[] m_data;
    }
    void Erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }
    T& operator[](int index)
    {
        return m_data[index];
    }
    int getLength();
};

template <typename T> // member functions defined outside the class
int Array<T>::getLength() { return m_length; } // class name is Array<T>, not Array
