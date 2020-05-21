#ifndef CONCREATE_RACE_H
#define CONCREATE_RACE_H

#include "race_interface.h"

class DragRace : Race {
public:
    DragRace(std::shared_ptr<Car> first_car, 
             std::shared_ptr<Car> second_car);
    bool Run_Race() override;
};


class RingRace : Race {
public:
    RingRace(std::shared_ptr<Car> first_car, 
             std::shared_ptr<Car> second_car);
    bool Run_Race() override;
};

#endif //CONCREATE_RACE_H