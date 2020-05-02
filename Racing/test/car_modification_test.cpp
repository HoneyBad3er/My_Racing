#include "gtest/gtest.h"
#include "concreatecarfactory.h"
#include "car.h"
#include "tmp_namespaces.h"


TEST(MODIFICATION_TEST, test_4) {
    std::shared_ptr<Car_Factory> f1_Factory = std::make_shared<Formula1_Car_Factory>();
    std::shared_ptr<Car> f1_car = f1_Factory->Create_Car();
    Pit::GoPit(f1_car);
    EXPECT_EQ(f1_car->get_power(), 1010);
    EXPECT_EQ(f1_car->get_weight(), 800);
    EXPECT_EQ(f1_car->get_controllability(), 125);
}