#include "String.h"

char& String::operator[](int index)
{
    return m_pString[index];
}

String String::operator+(const String& other)
{
    int size = m_length + other.m_length;
    String res(size);
    int counter = 0;
    for (int i = 0; i < m_length; i++)
    {
        res[counter++] = m_pString[i];
    }
    for (int i = 0; i < other.m_length; i++)
    {
        res[counter++] = other.m_pString[i];
    }

    res[size] = '\0';

    return res;
}

const String& String::operator=(const String& other)
{
    DestroyString();

    if (other.m_length > 0)
    {
        Allocate(other.m_length);
        for (int i = 0; i < m_length; i++)
        {
            m_pString[i] = other.m_pString[i];
        }
        m_pString[m_length] = '\0';
    }

    return *this;
}
