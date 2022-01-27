#pragma once
#include "Vehicle.h"
#include <iostream>
using namespace std;

class Truck : public Vehicle
{
protected:
    int numberOfSeats;
    int speedLimit;
    int loadCapacity;
public:
    Truck() : Vehicle()
    {
        type = Vehicle::TRUCK;
        numberOfSeats = 0;
        speedLimit = 0;
        loadCapacity = 0;
    }
    ~Truck() {}
    void Read()
    {
        cout << "Truck Weight:   ";
        cin >> weight;
        cout << "Number of seats:   ";
        cin >> numberOfSeats;
        cout << "Speed limit:   ";
        cin >> speedLimit;
        cout << "Load capacity:   ";
        cin >> loadCapacity;
    }
    void Write()
    {
        cout << "Truck Weight:   " << weight << endl;
        cout << "Number of seats:   " << numberOfSeats << endl;
        cout << "Speed limit:   " << speedLimit << endl;
        cout << "Load capacity:   " << loadCapacity << endl;
    }
};