#pragma once
#include "SinglePhaseDevice.h"
#include "ThreePhaseDevice.h"
#include <vector>

#define POWER_PER_PHASE_LIMIT 10

class Subscriber
{
public:
    typedef enum
    {
        LINE1_OVERLOADED,
        LINE2_OVERLOADED,
        LINE3_OVERLOADED,
        DISCONNECTED,
        WRONG_CONNECTION
    } Exception;

    Subscriber(void);
    ~Subscriber(void);

    void AttachSinglePhaseDevice(SinglePhaseDevice& device);
    void AttachThreePhaseDevice(ThreePhaseDevice& device);

protected:
    std::vector<SinglePhaseDevice> singlePhaseDevices;
    std::vector<ThreePhaseDevice> threePhaseDevices;

    double powerPerLine[3];
};
