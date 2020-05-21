#include "tracks.h"
#include <cstdlib>

std::shared_ptr<Car_Factory> Track::f1_factory = std::make_shared<Formula1_Car_Factory>();
std::shared_ptr<Car_Factory> Track::DTM_factory = std::make_shared<DTM_Car_Factory>();
std::shared_ptr<Car_Factory> Track::GT_factory = std::make_shared<GT_Car_Factory>();

Track::Track(std::string track_name, 
                   std::string message, 
                   std::vector<RacingSeries>& types) : 
    track_name(track_name),
    message(message) {
        for (RacingSeries type : types) {
            if (type == Formula1) {
                car_types.push_back(std::make_pair(type, f1_factory));
            }
            else if (type == DTM) {
                car_types.push_back(std::make_pair(type, GT_factory));
            }
            else if (type == GT) {
                car_types.push_back(std::make_pair(type, DTM_factory));
            }
        }
    }

std::shared_ptr<Car> Track::Get_Car() {
    if (car_types.size() == 1) {
        return car_types[0].second->Create_Car();
    }
    srand(time(NULL));
    size_t type_index = rand() % car_types.size();
    return car_types[type_index].second->Create_Car();
}

std::string Track::GetMessage() {
    return message;
}


std::string Track::GetName() {
    return track_name;
}


void Track::AddRoad(std::shared_ptr<Track> track) {
    roads_to.push_back(track);
}


const std::vector<std::shared_ptr<Track> >& Track::GetRoads() {
    return roads_to;
}