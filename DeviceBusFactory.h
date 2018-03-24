#ifndef DEVICE_BUS_FACTORY_H_
#define DEVICE_BUS_FACTORY_H_

#include "DeviceBusInterface.h"
#include "BasicDeviceBus.h"
#include "ZeroMQDeviceBus.h"
#include "RabbitMQDeviceBus.h"
#include "PubNubDeviceBus.h"

class DeviceBusFactory {
public:
    static DeviceBusInterface * getBasicDeviceBus();
    static DeviceBusInterface * getZeroMQDeviceBus();
    static DeviceBusInterface * getRabbitMQDeviceBus();
    static DeviceBusInterface * getPubNubDeviceBus();
};

#endif // DEVICE_BUS_FACTORY_H_

