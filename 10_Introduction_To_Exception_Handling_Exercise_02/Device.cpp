#include "Device.h"                        

Device::Device(void)
{
    name = "";
    power = 0;
}
Device::Device(std::string& nameOfDevice, double pow)
{
    name = nameOfDevice;
    power = pow;
}
Device::Device(const Device& other)
{
    name = other.name;
    power = other.power;
}
Device::~Device(void)
{
}
