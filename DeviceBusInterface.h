#ifndef DEVICE_BUS_INTERFACE_H_
#define DEVICE_BUS_INTERFACE_H_

#include <cstdint>
#include <functional>

struct BusDataInterface {
    virtual ~BusDataInterface() {}
};

class DeviceBusInterface {
public:
    virtual ~DeviceBusInterface() {}
    virtual bool CheckChannel(uint32_t channel) = 0;
    virtual void Publish(uint32_t channel, BusDataInterface * data) = 0;
    virtual void Subscribe(uint32_t channel, std::function<void(BusDataInterface *)> handler) = 0;
};

#endif // DEVICE_BUS_INTERFACE_H_

