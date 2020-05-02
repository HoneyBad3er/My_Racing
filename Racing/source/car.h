#ifndef CAR_H
#define CAR_H

enum RacingSeries {
    Formula1,
    DTM,
    GT
};

class Car {
public:
    Car(int power,
        int weight,
        int max_speed,
        int controllability,
        RacingSeries type,
        int number = 1);
    virtual ~Car() {};

    virtual void Race() const = 0;
    virtual const int get_power() const;
    virtual const int get_weight() const;
    virtual const int get_max_speed() const;
    virtual const int get_controllability() const;
protected:
    int _power;
    int _weight;
    int _max_speed;
    int _controllability;
    RacingSeries _type;
    int _number;
    friend class OnPitDecorator;
};

#endif // CAR_H
