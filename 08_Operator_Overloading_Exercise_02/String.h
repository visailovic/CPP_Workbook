#pragma once

class String
{
private:
    char* m_pString;
    int m_length;

    int CalculateLength(const char str[])
    {
        int length = 0;
        while (str[length] != '\0') length++;
        return length;
    }
    void Allocate(int size)
    {
        if (size > 0)
        {
            m_pString = new char[size + 1];
            m_length = size;
        }
    }
    void DestroyString()
    {
        if (m_pString)
        {
            delete[] m_pString;
            m_length = 0;
        }
    }
public:
    int GetLength() const { return m_length; }
    String()
    {
        m_pString = 0;
        m_length = 0;
    }
    String(const char str[])
    {
        m_pString = 0;
        m_length = 0;
        int length = CalculateLength(str);

        if (length > 0)
        {
            Allocate(length);
            for (int i = 0; i <= length; i++) m_pString[i] = str[i];
        }
    };
    String(int length)
    {
        Allocate(length);
    }
    String(const String& other)
    {
        m_pString = 0;
        m_length = 0;
        *this = other;
    }
    ~String()
    {
        DestroyString();
    }
    char& operator[](int index);
    String operator+(const String& other);
    const String& operator=(const String& other);
};
