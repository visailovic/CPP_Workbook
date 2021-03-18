#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Truck.h"

void PrintCars(Vehicle** array, int size)
{
    for (int i = 0; i < size; i++)
    {
        Vehicle* v = array[i];
        if (v->GetType() == Vehicle::CAR)
        {
            v->Write();
        }
    }
}

int main()
{
    cout << "Enter the number of vehicles:  ";
    int numberOfVehicles;
    cin >> numberOfVehicles;

    Vehicle** array = new Vehicle * [numberOfVehicles];

    for (int i = 0; i < numberOfVehicles; i++)
    {
        cout << "Enter the vechicle type: Car (1), Bus (2), Truck (3)";
        int n;
        cin >> n;
        switch (n)
        {
        case Vehicle::CAR:
            array[i] = new Car;
            break;
        case Vehicle::BUS:
            array[i] = new Bus;
            break;
        case Vehicle::TRUCK:
            array[i] = new Truck;
            break;
        default:
            cout << "Enter again...";
            i--;
            continue;
        }

        array[i]->Read();
    }

    PrintCars(array, numberOfVehicles);

    for (int i = 0; i < numberOfVehicles; i++)
    {
        delete array[i];
    }
    delete array;
}
