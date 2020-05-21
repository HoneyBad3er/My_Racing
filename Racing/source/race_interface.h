#ifndef RACE_INTERFACE_H
#define RACE_INTERFACE_H

#include "concreatecarfactory.h"
#include "car.h"
#include <vector>
#include <memory>

class Race {
public:
    Race(std::shared_ptr<Car> first_car, std::shared_ptr<Car> second_car);
    virtual bool Run_Race() = 0;
    virtual ~Race() {};
protected:
    std::shared_ptr<Car> first_car;
    std::shared_ptr<Car> second_car;
};

#endif // RACE_INTERFACE_H