#include "gtest/gtest.h"
#include "concreatecarfactory.h"
#include "car.h"


TEST(DTM_CREATING_TEST, test_2) {
    std::shared_ptr<Car_Factory> DTM_Factory = std::make_shared<DTM_Car_Factory>();
    std::shared_ptr<Car> dtm_car = DTM_Factory->Create_Car();
    EXPECT_EQ(dtm_car->get_power(), 750);
    EXPECT_EQ(dtm_car->get_weight(), 1200);
    EXPECT_EQ(dtm_car->get_max_speed(), 380);
    EXPECT_EQ(dtm_car->get_controllability(), 70);
}
