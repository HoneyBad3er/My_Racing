#ifndef CAR_MODIFICATIONS_H
#define CAR_MODIFICATIONS_H
#include <memory>
#include "car.h"
#include "carlist.h"

class OnPitDecorator {
public:
    OnPitDecorator(std::shared_ptr<Car> car);
    void Power_Up();
    void Change_Tyres();
    void Change_Front_Wing();
private:
    std::shared_ptr<Car> modified_car;
};

#endif // CAR_MODIFICATIONS_H