#ifndef PUBNUB_DEVICE_BUS_H_
#define PUBNUB_DEVICE_BUS_H_

#include "DeviceBusInterface.h"

class PubNubDeviceBus : public DeviceBusInterface {
public:
    PubNubDeviceBus() {}
    ~PubNubDeviceBus() {}
    bool CheckChannel(uint32_t channel) { return false; }
    void Publish(uint32_t channel, BusDataInterface * data) {}
    void Subscribe(uint32_t channel, std::function<void(BusDataInterface *)> handler) {}
};

#endif // PUBNUB_DEVICE_BUS_H_

