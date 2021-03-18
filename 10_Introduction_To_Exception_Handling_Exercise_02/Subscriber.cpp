#include "Subscriber.h"
#include "iostream"

Subscriber::Subscriber(void)
{
    powerPerLine[0] = 0;
    powerPerLine[1] = 0;
    powerPerLine[2] = 0;
}

Subscriber::~Subscriber(void)
{
}

void Subscriber::AttachSinglePhaseDevice(SinglePhaseDevice& device)
{
    double powerSum = powerPerLine[(int)device.GetPhase()] + device.GetPower();

    if (powerSum > POWER_PER_PHASE_LIMIT)
    {
        if (device.GetPhase() == Device::LINE_1) throw LINE1_OVERLOADED;
        if (device.GetPhase() == Device::LINE_2) throw LINE2_OVERLOADED;
        if (device.GetPhase() == Device::LINE_3) throw LINE3_OVERLOADED;

    }

    singlePhaseDevices.push_back(device);
    powerPerLine[(int)device.GetPhase()] += device.GetPower();
}

void Subscriber::AttachThreePhaseDevice(ThreePhaseDevice& device)
{
    if (device.GetPhase1() == device.GetPhase2() ||
        device.GetPhase1() == device.GetPhase3() ||
        device.GetPhase2() == device.GetPhase3())
    {
        throw(WRONG_CONNECTION);
    }

    double powerSum1 = powerPerLine[0] + device.GetPower() / 3;
    double powerSum2 = powerPerLine[1] + device.GetPower() / 3;
    double powerSum3 = powerPerLine[2] + device.GetPower() / 3;

    if (powerSum1 > POWER_PER_PHASE_LIMIT) throw LINE1_OVERLOADED;
    if (powerSum2 > POWER_PER_PHASE_LIMIT) throw LINE2_OVERLOADED;
    if (powerSum3 > POWER_PER_PHASE_LIMIT) throw LINE3_OVERLOADED;

    threePhaseDevices.push_back(device);
    powerPerLine[0] += device.GetPower() / 3;
    powerPerLine[1] += device.GetPower() / 3;
    powerPerLine[2] += device.GetPower() / 3;
}
