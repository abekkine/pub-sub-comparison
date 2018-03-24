#ifndef BASIC_DEVICE_BUS_H_
#define BASIC_DEVICE_BUS_H_

#include "DeviceBusInterface.h"

class BasicDeviceBus : public DeviceBusInterface {
public:
    BasicDeviceBus() {}
    ~BasicDeviceBus() {}
    bool CheckChannel(uint32_t channel) { return false; }
    void Publish(uint32_t channel, BusDataInterface * data) {}
    void Subscribe(uint32_t channel, std::function<void(BusDataInterface *)> handler) {}
};

#endif // BASIC_DEVICE_BUS_H_

