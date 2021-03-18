#include "SinglePhaseDevice.h"         

SinglePhaseDevice::SinglePhaseDevice(void) : Device()
{
    phase = Device::DISCONNECTED;
}

SinglePhaseDevice::SinglePhaseDevice(std::string& name, double pow, Device::Phase PHASE) : Device(name, pow)
{
    phase = PHASE;
}

SinglePhaseDevice::SinglePhaseDevice(const SinglePhaseDevice& other) : Device(other)
{
    phase = other.phase;
}

SinglePhaseDevice::~SinglePhaseDevice(void)
{

}