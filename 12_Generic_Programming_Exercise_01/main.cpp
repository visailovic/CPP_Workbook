#include <iostream>
#include "IntArray.h"
#include "DoubleArray.h"

using namespace std;

int main()
{
    IntArray intArray(5);
    DoubleArray doubleArray(5);

    for (int i = 0; i < 5; i++) intArray[i] = i + 1;
    for (int i = 0; i < 5; i++) cout << intArray[i] << " ";

    for (int i = 0; i < 5; i++) doubleArray[i] = i + 0.5;
    for (int i = 0; i < 5; i++) cout << doubleArray[i] << " ";

    return 0;
}
