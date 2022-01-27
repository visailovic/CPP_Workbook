#pragma once
class Vehicle
{
public:
    typedef enum
    {
        UNKNOWN,
        CAR,
        BUS,
        TRUCK
    }VehicleType;

    Vehicle()
    {
        weight = 0;
        type = VehicleType::UNKNOWN;
    }

protected:
    int weight;
    VehicleType type;
public:
    VehicleType GetType() { return type; }
    virtual void Read() = 0;
    virtual void Write() = 0;
};
