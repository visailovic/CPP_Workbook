#pragma once                  
#include "Device.h"
class ThreePhaseDevice : public Device
{
public:
    ThreePhaseDevice(void);
    ~ThreePhaseDevice(void);
    ThreePhaseDevice(const ThreePhaseDevice& other);
    ThreePhaseDevice(std::string& name, double pow, Device::Phase ph1, Device::Phase ph2, Device::Phase ph3);

    Device::Phase GetPhase1() { return phase1; };
    Device::Phase GetPhase2() { return phase2; };
    Device::Phase GetPhase3() { return phase3; };

protected:
    Device::Phase phase1;
    Device::Phase phase2;
    Device::Phase phase3;
};
