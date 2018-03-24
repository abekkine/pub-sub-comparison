#ifndef BASIC_DEVICE_BUS_H_
#define BASIC_DEVICE_BUS_H_

#include "DeviceBusInterface.h"

#include <unordered_map>
#include <vector>

class BasicDeviceBus : public DeviceBusInterface {
public:
    BasicDeviceBus() {}
    ~BasicDeviceBus() {}
    bool CheckChannel(uint32_t channel) {
        auto found = subscribers_.find(channel);
        if (found != subscribers_.end()) {
            return true;
        }
        else {
            return false;
        }
    }
    void Publish(uint32_t channel, BusDataInterface * data) {

        if (CheckChannel(channel)) {
            for (auto handler : subscribers_[channel]) {

                handler(data);
            }
        }
    }
    void Subscribe(uint32_t channel, std::function<void(BusDataInterface *)> handler) {
   
        if (false == CheckChannel(channel)) {

            std::vector<std::function<void(BusDataInterface *)>> v;
            subscribers_[channel] = v;
        }

        subscribers_[channel].push_back(handler);
    }

private:
    std::unordered_map<uint32_t, std::vector<std::function<void(BusDataInterface *)>>> subscribers_;
};

#endif // BASIC_DEVICE_BUS_H_

