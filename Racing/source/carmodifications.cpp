#include "carmodifications.h"
#include <iostream>

OnPitDecorator::OnPitDecorator(std::shared_ptr<Car> car): modified_car(car) {}

void OnPitDecorator::Power_Up() {
    std::cout << "Setting power up..." << "\n";
    modified_car->_power += 10;
}

void OnPitDecorator::Change_Tyres() {
    std::cout << "Changing tyres..." << "\n";
    modified_car->_controllability += 10;
}

void OnPitDecorator::Change_Front_Wing() {
    std::cout << "Changing front wing..." << "\n";
    modified_car->_controllability += 15;
}