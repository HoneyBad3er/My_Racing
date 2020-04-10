#ifndef CARLIST_H
#define CARLIST_H
#pragma once

#include "car.h"
#include <iostream>


class Formula1_Car : public Car {
public:
    Formula1_Car() : Car(1000, 800, 400, 100) {};
    void Race() const override;
};


class DTM_Car : public Car {
public:
    DTM_Car() : Car(750, 1200, 380, 70) {};
    void Race() const override;
};


class GT_Car : public Car {
public:
    GT_Car() : Car(820, 1300, 420, 65) {};
    void Race() const override;
};

#endif // CARLIST_H
