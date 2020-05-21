#include "racing_team.h"
#include <iostream>

void RacingTeam::Print() {
        for (size_t i = 0; i < quantity; ++i) {
            std::cout << i << " " << cars[i]->GetType() << "\n";
        }
}

void RacingTeam::AddCar(std::shared_ptr<Car> person) {
    cars.push_back(person);
}

std::shared_ptr<Car> RacingTeam::GetCar(int number) {
    return cars[number];
}

void RacingTeam::RemoveCar(int number) {
    cars.erase(cars.begin() + number);
}

size_t RacingTeam::Get_quantity() {
    return cars.size();
}

void RacingTeam::PrintTeam() {
    std::cout << "Выбери машину";
    for (size_t i = 0; i < cars.size(); ++i) {
        if (i % 5 == 0) {
            std::cout << "\n";
        }
        std::cout << i << " " << cars[i]->GetType() << "; ";
    }
    std::cout << "\nВведи номер: ";
}