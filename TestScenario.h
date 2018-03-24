#ifndef TEST_SCENARIO_H_
#define TEST_SCENARIO_H_

#include <vector>
#include <thread>

struct TestData : public BusDataInterface {
    double a, b;
};

class TestScenario {
public:
    explicit TestScenario(int size)
    : kTestSize(size)
    , data_{}
    , device_bus_(0)
    {
        data_.size = kTestSize;
        data_.buffer_index = 0;
        data_.number_buffer = new double[kTestSize * 2];
        data_.operation_buffer = new char[kTestSize];

        srand48(88217);
        for (int i=0; i<kTestSize; ++i) {
            data_.number_buffer[2*i + 0] = drand48() * 10.0;
            data_.number_buffer[2*i + 1] = drand48() * 10.0;
            data_.operation_buffer[i] = drand48() > 0.5 ? '*' : '+';
        }
    }
    ~TestScenario() {
        delete [] data_.number_buffer;
        delete [] data_.operation_buffer;
    }
    void RegisterDeviceBus(DeviceBusInterface *bus) {
        device_bus_ = bus;
    }
    void Perform() {
        addition_results_.clear();
        multiplication_results_.clear();
        data_.buffer_index = 0;

        device_bus_->Subscribe(1, std::bind(&TestScenario::AddNumbers, this, std::placeholders::_1));
        device_bus_->Subscribe(2, std::bind(&TestScenario::MultiplyNumbers, this, std::placeholders::_1));

        std::thread generator(&TestScenario::Generate, this);

        generator.join();
    }
    void AddNumbers(BusDataInterface * data) {
        TestData * numbers = static_cast<TestData *>(data);
        if (numbers != 0) {
            addition_results_.push_back(numbers->a + numbers->b);
        }
    }
    void MultiplyNumbers(BusDataInterface * data) {
        TestData * numbers = static_cast<TestData *>(data);
        if (numbers != 0) {
            multiplication_results_.push_back(numbers->a * numbers->b);
        }
    }
    void Generate() {

        TestData data;
        for (int i=0; i<kTestSize; ++i) {
            data.a = data_.number_buffer[2*i+0];
            data.b = data_.number_buffer[2*i+1];
            switch (data_.operation_buffer[i]) {
                case '+':
                    device_bus_->Publish(1, &data);
                    break;
                case '*':
                    device_bus_->Publish(2, &data);
                    break;
                default:
                    break;
            }
        }
    }

private:
    const int kTestSize;
    struct Data {
        int size;
        int buffer_index;
        double * number_buffer;
        char * operation_buffer;
    } data_;

    std::vector<double> addition_results_;
    std::vector<double> multiplication_results_;

    DeviceBusInterface * device_bus_;
};

#endif // TEST_SCENARIO_H_

