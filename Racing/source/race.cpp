#include "race.h"


Car_position::Car_position(std::shared_ptr<Car> car, 
                           size_t pos): car(car), position(pos) {}

Race::Race(std::vector< std::shared_ptr<Car_position> >& cars) : _carQuantity(cars.size()), _cars(cars) {

}

void Race::In_Race() {

}

void Race::On_Pit() {
    
}