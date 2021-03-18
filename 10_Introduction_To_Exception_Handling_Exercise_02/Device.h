#pragma once                             
#include <string>
using namespace std;
class Device
{
public:

    typedef enum
    {
        LINE_1,
        LINE_2,
        LINE_3,
        DISCONNECTED
    } Phase;
    Device(void);
    Device(std::string& nameOfDevice, double pow);
    Device(const Device& other);
    ~Device(void);
    double GetPower() { return power; }
    std::string GetName() { return name; }

protected:
    std::string name;
    double power;
};
