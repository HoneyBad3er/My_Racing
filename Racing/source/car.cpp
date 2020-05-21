#include "car.h"

Car::Car(int power,
         int weight,
         int max_speed,
         int controllability,
         RacingSeries type,
         int number) :
    _power(power), _weight(weight),
    _max_speed(max_speed), _controllability(controllability), _type(type), _number(number) {}

const int Car::get_power() const {
     return _power;
}

const int Car::get_weight() const {
     return _weight;
}

const int Car::get_max_speed() const {
     return _max_speed;
}

const int Car::get_controllability() const {
     return _controllability;
}