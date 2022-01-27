#include "Subscriber.h"
#include <string>
#include <iostream>

void AttachSinglePhaseDevices(Subscriber& subscriber)
{
    char ch;
    do
    {
        std::string name;
        cout << "Enter the name of single phase device: " << endl;
        cin >> name;

        double power;
        cout << "Enter the power of single phase device: " << endl;
        cin >> power;

        int line;
        do
        {
            cout << "Enter the line that device should be connected to (1,2,3):" << endl;
            cin >> line;
        } while (line != 1 && line != 2 && line != 3);

        SinglePhaseDevice device(name, power, Device::Phase(line - 1));
        try
        {
            subscriber.AttachSinglePhaseDevice(device);
        }
        catch (Subscriber::Exception& e)
        {
            cout << "Device " << device.GetName() << "Cannot be connected!" << endl;

            if (e == Subscriber::LINE1_OVERLOADED)
                cout << "Line 1 is overloaded!" << endl;
            if (e == Subscriber::LINE2_OVERLOADED)
                cout << "Line 2 is overloaded!" << endl;
            if (e == Subscriber::LINE3_OVERLOADED)
                cout << "Line 3 is overloaded!" << endl;
        }

        cout << "Enter another device? (Y - yes, any other key - no)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void AttachThreePhaseDevices(Subscriber& subscriber)
{
    char ch;
    do
    {
        std::string name;
        cout << "Enter the name of three phase device: " << endl;
        cin >> name;

        double power;
        cout << "Enter the power of three phase device: " << endl;
        cin >> power;

        ThreePhaseDevice device(name, power,
            Device::LINE_1, Device::LINE_2, Device::LINE_3);
        try
        {
            subscriber.AttachThreePhaseDevice(device);
        }
        catch (Subscriber::Exception& e)
        {
            cout << "Device " << device.GetName() << "Cannot be connected!" << endl;

            if (e == Subscriber::LINE1_OVERLOADED)
                cout << "Line 1 is overloaded!" << endl;
            if (e == Subscriber::LINE2_OVERLOADED)
                cout << "Line 2 is overloaded!" << endl;
            if (e == Subscriber::LINE3_OVERLOADED)
                cout << "Line 3 is overloaded!" << endl;
        }

        cout << "Enter another device? (Y - yes, any other key - no)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

int main()
{
    Subscriber subscriber;

    AttachSinglePhaseDevices(subscriber);

    AttachThreePhaseDevices(subscriber);

    return 0;
}
