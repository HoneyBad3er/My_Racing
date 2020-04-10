#ifndef CONCREATECARFACTORY_H
#define CONCREATECARFACTORY_H
#pragma once

#include "carfactory.h"
#include "carlist.h"
#include <memory>

class Formula1_Car_Factory : public Car_Factory {
public:
    std::shared_ptr<Car> Create_Car() const override;
};

class DTM_Car_Factory : public Car_Factory {
public:
    std::shared_ptr<Car> Create_Car() const override;
};

class GT_Car_Factory : public Car_Factory {
public:
    std::shared_ptr<Car> Create_Car() const override;
};

#endif // CONCREATECARFACTORY_H
