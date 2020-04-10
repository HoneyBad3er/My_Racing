#include "concreatecarfactory.h"

std::shared_ptr<Car> Formula1_Car_Factory :: Create_Car() const {
    return std::make_shared<Formula1_Car>();
}

std::shared_ptr<Car> DTM_Car_Factory :: Create_Car() const {
    return std::make_shared<DTM_Car>();
}

std::shared_ptr<Car> GT_Car_Factory :: Create_Car() const {
    return std::make_shared<GT_Car>();
}
