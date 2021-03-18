#include "ThreePhaseDevice.h"            

ThreePhaseDevice::ThreePhaseDevice(void) : Device()
{
    phase1 = Device::DISCONNECTED;
    phase2 = Device::DISCONNECTED;
    phase3 = Device::DISCONNECTED;
}
ThreePhaseDevice::ThreePhaseDevice(std::string& name, double pow, Device::Phase ph1, Device::Phase ph2, Device::Phase ph3) : Device(name, pow)
{
    phase1 = ph1;
    phase2 = ph2;
    phase3 = ph3;
}
ThreePhaseDevice::ThreePhaseDevice(const ThreePhaseDevice& other) : Device(other)
{
    phase1 = other.phase1;
    phase2 = other.phase2;
    phase3 = other.phase3;
}
ThreePhaseDevice::~ThreePhaseDevice(void)
{
}
