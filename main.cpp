#include "DeviceBusFactory.h"
#include "TestScenario.h"

int main() {

    TestScenario * test = new TestScenario(100000);
    DeviceBusInterface * bus = 0;

    // Basic device bus tests.
    bus = DeviceBusFactory::getBasicDeviceBus();
    test->RegisterDeviceBus(bus);
    test->Perform();
    delete bus;
    
    // ZeroMQ device bus tests.
    bus = DeviceBusFactory::getZeroMQDeviceBus();
    test->RegisterDeviceBus(bus);
    test->Perform();
    delete bus;

    // RabbitMQ device bus tests.
    bus = DeviceBusFactory::getRabbitMQDeviceBus();
    test->RegisterDeviceBus(bus);
    test->Perform();
    delete bus;

    // PubNub device bus tests.
    bus = DeviceBusFactory::getPubNubDeviceBus();
    test->RegisterDeviceBus(bus);
    test->Perform();
    delete bus;

    return 0;
}

