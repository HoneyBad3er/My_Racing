#include "carlist.h"


Formula1_Car::Formula1_Car() : 
    Car(1000, 800, 400, 100, Formula1) {}

std::string Formula1_Car::GetType() {
    return "Formula_1";
}

void Formula1_Car::Race() const {
    std::cout << "Formula1_Car races..." << std::endl;
}


DTM_Car::DTM_Car() : 
    Car(750, 1200, 380, 70, DTM) {}

std::string DTM_Car::GetType() {
    return "DTM";
}

void DTM_Car::Race() const {
    std::cout << "DTM_Car races..." << std::endl;

}


GT_Car::GT_Car() : 
    Car(820, 1300, 420, 65, GT) {}

std::string GT_Car::GetType() {
    return "GT";
}

void GT_Car::Race() const {
    std::cout << "GT_Car races..." << std::endl;

}
