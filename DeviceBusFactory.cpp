#include "DeviceBusFactory.h"

DeviceBusInterface * DeviceBusFactory::getBasicDeviceBus() {
    DeviceBusInterface * bus = 0;

    bus = new BasicDeviceBus();

    return bus;
}

DeviceBusInterface * DeviceBusFactory::getZeroMQDeviceBus() {
    DeviceBusInterface * bus = 0;

    bus = new ZeroMQDeviceBus();

    return bus;
}

DeviceBusInterface * DeviceBusFactory::getRabbitMQDeviceBus() {
    DeviceBusInterface * bus = 0;

    bus = new RabbitMQDeviceBus();

    return bus;
}

DeviceBusInterface * DeviceBusFactory::getPubNubDeviceBus() {
    DeviceBusInterface * bus = 0;

    bus = new PubNubDeviceBus();

    return bus;
}

