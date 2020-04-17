#include "gtest/gtest.h"
#include "concreatecarfactory.h"
#include "car.h"


TEST(GT_CREATING_TEST, test_1) {
    std::shared_ptr<Car_Factory> GT_Factory = std::make_shared<GT_Car_Factory>();
    std::shared_ptr<Car> gt_car = GT_Factory->Create_Car();
    EXPECT_EQ(gt_car->get_power(), 820);
    EXPECT_EQ(gt_car->get_weight(), 1300);
    EXPECT_EQ(gt_car->get_max_speed(), 420);
    EXPECT_EQ(gt_car->get_controllability(), 65);
}
