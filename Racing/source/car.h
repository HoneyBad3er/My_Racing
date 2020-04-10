#ifndef CAR_H
#define CAR_H
#pragma once


class Car {
public:
    Car(int power,
        int weight,
        int max_speed,
        int controllability);

    virtual void Race() const = 0;
    virtual ~Car() {};
    virtual const int get_power() const;
    virtual const int get_weight() const;
    virtual const int get_max_speed() const;
    virtual const int get_controllability() const;
protected:
    int _power;
    int _weight;
    int _max_speed;
    int _controllability;
};

#endif // CAR_H
