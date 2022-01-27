#pragma once
#include <iostream>
using namespace std;
char errorMessages[3][20] = { {"Out of range!\n\n"}, {"Empty array!\n\n"}, {"Bad allocation!\n\n"} };

class Array
{
public:
    enum Error
    {
        OUT_OF_RANGE = 0,
        EMPTY_ARRAY = 1,
        BAD_ALLOCATION = 2
    };
    Array()
    {
        data = 0;
        size = 0;
    }
    Array(int size)
    {
        try
        {
            Allocate(size);
        }
        catch (Error& errorCode)
        {
            cout << errorMessages[errorCode];
        }
    }
    ~Array()
    {
        if (data) delete[] data;
    }
    void SetValueAt(int index, int value)
    {
        if (size == 0)
            throw EMPTY_ARRAY;
        if (index < 0 || index >= size)
            throw OUT_OF_RANGE;
        data[index] = value;
    }
    int& operator[](int index)
    {
        return data[index];
    }
    int GetSize() { return size; }

private:
    int* data;
    int size;

    void Allocate(int sizeOfArray)
    {
        data = 0;
        size = 0;
        if (sizeOfArray <= 0)
        {
            throw Array::BAD_ALLOCATION;
        }
        data = new int[sizeOfArray];
        size = sizeOfArray;
        for (int i = 0; i < size; i++) data[i] = 0;
    }
};
