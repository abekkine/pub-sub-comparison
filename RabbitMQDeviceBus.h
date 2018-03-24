#ifndef RABBITMQ_DEVICE_BUS_H_
#define RABBITMQ_DEVICE_BUS_H_

#include "DeviceBusInterface.h"

class RabbitMQDeviceBus : public DeviceBusInterface {
public:
    RabbitMQDeviceBus() {}
    ~RabbitMQDeviceBus() {}
    bool CheckChannel(uint32_t channel) { return false; }
    void Publish(uint32_t channel, BusDataInterface * data) {}
    void Subscribe(uint32_t channel, std::function<void(BusDataInterface *)> handler) {}
};

#endif // RABBITMQ_DEVICE_BUS_H_

