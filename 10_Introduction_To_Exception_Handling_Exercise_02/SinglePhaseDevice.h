#pragma once                  
#include <string>
#include "Device.h"
class SinglePhaseDevice : public Device
{
public:
    SinglePhaseDevice(void);
    SinglePhaseDevice(std::string& name, double pow, Device::Phase PHASE);
    SinglePhaseDevice(const SinglePhaseDevice& other);
    ~SinglePhaseDevice(void);
    Device::Phase GetPhase() { return phase; };
protected:
    Device::Phase phase;
};
