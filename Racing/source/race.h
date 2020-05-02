#include "concreatecarfactory.h"
#include "car.h"
#include <vector>
#include <memory>


struct Car_position {
    Car_position(std::shared_ptr<Car> car, size_t pos);
    std::shared_ptr<Car> car;
    size_t position;
};

class Race {
public:
    Race(std::vector< std::shared_ptr<Car_position> >& cars);
    void In_Race();
    void On_Pit();
private:
    size_t _carQuantity;
    std::vector< std::shared_ptr<Car_position> > _cars;
};