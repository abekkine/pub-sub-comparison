#include "DeviceBusFactory.h"
#include "TestScenario.h"

#include <omp.h>

int main() {

    TestScenario * test = new TestScenario(100000);
    DeviceBusInterface * bus = 0;

    double start = omp_get_wtime();
    test->DumpExpectedResults();
    printf("Reference : %.5f\n", omp_get_wtime() - start);
    puts("-----");

    // Basic device bus tests.
    bus = DeviceBusFactory::getBasicDeviceBus();
    test->RegisterDeviceBus(bus);
    start = omp_get_wtime();
    test->Perform();
    printf("BasicDeviceBus : %.5f\n", omp_get_wtime() - start);
    delete bus;
    
    puts("-----");
    // ZeroMQ device bus tests.
    bus = DeviceBusFactory::getZeroMQDeviceBus();
    test->RegisterDeviceBus(bus);
    start = omp_get_wtime();
    test->Perform();
    printf("ZeroMQDeviceBus : %.5f\n", omp_get_wtime() - start);
    delete bus;

    puts("-----");
    // RabbitMQ device bus tests.
    bus = DeviceBusFactory::getRabbitMQDeviceBus();
    test->RegisterDeviceBus(bus);
    start = omp_get_wtime();
    test->Perform();
    printf("RabbitMQDeviceBus : %.5f\n", omp_get_wtime() - start);
    delete bus;

    puts("-----");
    // PubNub device bus tests.
    bus = DeviceBusFactory::getPubNubDeviceBus();
    test->RegisterDeviceBus(bus);
    start = omp_get_wtime();
    test->Perform();
    printf("PubNubDeviceBus : %.5f\n", omp_get_wtime() - start);
    delete bus;

    puts("-----");
    return 0;
}

