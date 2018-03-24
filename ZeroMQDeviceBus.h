#ifndef ZEROMQ_DEVICE_BUS_H_
#define ZEROMQ_DEVICE_BUS_H_

#include "DeviceBusInterface.h"

#include <iostream>

class ZeroMQDeviceBus : public DeviceBusInterface {
public:
    ZeroMQDeviceBus() {
        std::cout << "ZeroMQDeviceBus()\n";
    }
    ~ZeroMQDeviceBus() {
        std::cout << "~ZeroMQDeviceBus()\n";
    }
    bool CheckChannel(uint32_t channel) { 
        return false;
    }
    void Publish(uint32_t channel, BusDataInterface * data) {
    }
    void Subscribe(uint32_t channel, std::function<void(BusDataInterface *)> handler) {
        std::cout << "ZMQ::Subscribe(" << channel << ", ...)\n";
    }
};

#endif // ZEROMQ_DEVICE_BUS_H_

