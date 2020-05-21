#pragma once

#include <vector>
#include "carfactory.h"
#include "car.h"

class RacingTeam {
public:
    RacingTeam() = default;
    void AddCar(std::shared_ptr<Car> car);
    std::shared_ptr<Car> GetCar(int carNum);
    void RemoveCar(int carNum);
    size_t Get_quantity();
    void PrintTeam();
    void Print();
private:
    size_t quantity;
    std::vector< std::shared_ptr<Car> > cars;

};
