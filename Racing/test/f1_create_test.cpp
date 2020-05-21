#include "gtest/gtest.h"
#include "concreatecarfactory.h"
#include "car.h"


TEST(F1_CREATING_TEST, test_1) {
    std::shared_ptr<Car_Factory> f1_Factory = std::make_shared<Formula1_Car_Factory>();
    std::shared_ptr<Car> f1_car = f1_Factory->Create_Car();
    EXPECT_EQ(f1_car->get_power(), 1000);
    EXPECT_EQ(f1_car->get_weight(), 800);
    EXPECT_EQ(f1_car->get_max_speed(), 400);
    EXPECT_EQ(f1_car->get_controllability(), 100);
}
