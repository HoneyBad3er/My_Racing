#include "gtest/gtest.h"
#include "concreatecarfactory.h"
#include "car.h"


TEST(CREATING_TEST, test_1) {
    //arrange
    //act
    //assert
    std::shared_ptr<Car_Factory> f1_Factory = std::make_shared<Formula1_Car_Factory>();
    std::shared_ptr<Car_Factory> DTM_Factory = std::make_shared<DTM_Car_Factory>();
    std::shared_ptr<Car_Factory> GT_Factory = std::make_shared<GT_Car_Factory>();
    std::shared_ptr<Car> f1_car = f1_Factory->Create_Car();
    std::shared_ptr<Car> dtm_car = DTM_Factory->Create_Car();
    std::shared_ptr<Car> gt_car = GT_Factory->Create_Car();
    EXPECT_EQ(f1_car->get_power(), 1000);
    EXPECT_EQ(f1_car->get_weight(), 800);
    EXPECT_EQ(f1_car->get_max_speed(), 400);
    EXPECT_EQ(f1_car->get_controllability(), 100);
    EXPECT_EQ(dtm_car->get_power(), 750);
    EXPECT_EQ(dtm_car->get_weight(), 1200);
    EXPECT_EQ(dtm_car->get_max_speed(), 380);
    EXPECT_EQ(dtm_car->get_controllability(), 70);
    EXPECT_EQ(gt_car->get_power(), 820);
    EXPECT_EQ(gt_car->get_weight(), 1300);
    EXPECT_EQ(gt_car->get_max_speed(), 420);
    EXPECT_EQ(gt_car->get_controllability(), 65);
}
