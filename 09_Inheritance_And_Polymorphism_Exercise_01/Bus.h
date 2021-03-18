#pragma once
#include "Vehicle.h"
#include <iostream>
using namespace std;

class Bus : public Vehicle
{
protected:
    int numberOfSeats;
    int speedLimit;
public:
    Bus() : Vehicle()
    {
        type = Vehicle::BUS;
        numberOfSeats = 0;
        speedLimit = 0;
    }
    ~Bus() {}
    void Read()
    {
        cout << "Bus Weight:   ";
        cin >> weight;
        cout << "Number of seats:   ";
        cin >> numberOfSeats;
        cout << "Speed limit:   ";
        cin >> speedLimit;
    }
    void Write()
    {
        cout << "Bus Weight:   " << weight << endl;
        cout << "Number of seats:   " << numberOfSeats << endl;
        cout << "Speed limit:   " << speedLimit << endl;
    }
};