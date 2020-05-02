#include <iostream>
#include "concreatecarfactory.h"
#include "car.h"
#include "tmp_namespaces.h"


int main() {
    std::shared_ptr<Car_Factory> f1_Factory = std::make_shared<Formula1_Car_Factory>();
    std::shared_ptr<Car_Factory> DTM_Factory = std::make_shared<DTM_Car_Factory>();
    std::shared_ptr<Car_Factory> GT_Factory = std::make_shared<GT_Car_Factory>();
    std::shared_ptr<Car> f1_car = f1_Factory->Create_Car();
    std::shared_ptr<Car> dtm_car = DTM_Factory->Create_Car();
    std::shared_ptr<Car> gt_car = GT_Factory->Create_Car();
    f1_car->Race();
    dtm_car->Race();
    gt_car->Race();
    Pit::GoPit(f1_car);
    Pit::GoPit(dtm_car);
    Pit::GoPit(gt_car);
    return 0;
}
