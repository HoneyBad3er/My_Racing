#ifndef CARLIST_H
#define CARLIST_H
#include "car.h"
#include <iostream>


class Formula1_Car : public Car {
public:
    Formula1_Car();
    std::string GetType() override;
    void Race() const override;
};


class DTM_Car : public Car {
public:
    DTM_Car();
    std::string GetType() override;
    void Race() const override;
};


class GT_Car : public Car {
public:
    GT_Car();
    std::string GetType() override;
    void Race() const override;
};

#endif // CARLIST_H
