#include "race_interface.h"

Race::Race(std::shared_ptr<Car> first_car, 
           std::shared_ptr<Car> second_car) : first_car(first_car), 
                                              second_car(second_car) {}
