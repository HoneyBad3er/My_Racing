#ifndef CARFACTORY_H
#define CARFACTORY_H
#include "car.h"
#include <memory>


class Car_Factory {
public:
    virtual std::shared_ptr<Car> Create_Car() const = 0;
    virtual ~Car_Factory() {};
};

#endif // CARFACTORY_H
