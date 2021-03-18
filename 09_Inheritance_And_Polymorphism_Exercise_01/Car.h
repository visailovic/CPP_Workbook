#pragma once
#include "Vehicle.h"
#include <iostream>
using namespace std;

class Car : public Vehicle
{
protected:
    int numberOfSeats;
public:
    Car() : Vehicle()
    {
        type = Vehicle::CAR;
        numberOfSeats = 0;
    }
    ~Car() {}
    void Read()
    {
        cout << "Car Weight:   ";
        cin >> weight;
        cout << "Number of seats:   ";
        cin >> numberOfSeats;
    };
    void Write()
    {
        cout << "Car Weight:   " << weight << endl;
        cout << "Number of seats:   " << numberOfSeats << endl;
    };
};
