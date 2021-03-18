#include <iostream>

template <class T, int size> // size is the expression parameter
class StaticArray
{
private:
    // The expression parameter controls the size of the array
    T m_array[size];

public:
    T* getArray();

    T& operator[](int index)
    {
        return m_array[index];
    }
};

// Showing how a function for a class with an expression parameter is defined outside of the class
template <class T, int size>
T* StaticArray<T, size>::getArray()
{
    return m_array;
}

int main()
{
    StaticArray<int, 12> intArray;

    for (int count = 0; count < 12; ++count)
        intArray[count] = count;

    for (int count = 11; count >= 0; --count)
        std::cout << intArray[count] << " ";
    std::cout << '\n';

    StaticArray<double, 4> doubleArray;

    for (int count = 0; count < 4; ++count)
        doubleArray[count] = 4.4 + 0.1 * count;

    for (int count = 0; count < 4; ++count)
        std::cout << doubleArray[count] << ' ';

    return 0;
}