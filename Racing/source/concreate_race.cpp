#include "concreate_race.h"
#include <cstdlib>
#include "time.h"

DragRace::DragRace(std::shared_ptr<Car> first_car, 
                    std::shared_ptr<Car> second_car) : Race(first_car, second_car) {};

bool DragRace::Run_Race() {
    srand(time(NULL));
    int using_rand = rand() % 100;
    double chance1 = static_cast<double>(using_rand) / 100 
                     * (first_car->get_power() + first_car->get_max_speed()) 
                     / first_car->get_weight();
    
    srand(time(NULL));
    using_rand = rand() % 100;
    double chance2 = static_cast<double>(using_rand) / 100 
                     * (second_car->get_power() + second_car->get_max_speed()) 
                     / second_car->get_weight();

    if (chance1 >= chance2) {
        return true;
    }
    else {
        return false;
    }
    return false;
}

RingRace::RingRace(std::shared_ptr<Car> first_car, 
                    std::shared_ptr<Car> second_car) : Race(first_car, second_car) {};

bool RingRace::Run_Race() {
    srand(time(NULL));
    int using_rand = rand() % 100;
    double chance1 = static_cast<double>(using_rand) / 100 
                     * (first_car->get_power() + first_car->get_controllability()) 
                     / first_car->get_weight();
    
    srand(time(NULL));
    using_rand = rand() % 100;
    double chance2 = static_cast<double>(using_rand) / 100 
                     * (second_car->get_power() + second_car->get_controllability()) 
                     / second_car->get_weight();

    if (chance1 >= chance2) {
        return true;
    }
    else {
        return false;
    }
    return false;
}