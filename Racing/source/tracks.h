#ifndef TRACKS_H
#define TRACKS_H
#include "carfactory.h"
#include "concreatecarfactory.h"
#include "car.h"
#include <memory>
#include <vector>
#include <string>
#include <utility>

class Track {
public:
    Track(std::string track_name, std::string message, std::vector<RacingSeries>& types);
    ~Track() {};
    std::shared_ptr<Car> Get_Car();
    const std::vector<std::shared_ptr<Track> >& GetRoads();
    std::string GetMessage();
    std::string GetName();
    void AddRoad(std::shared_ptr<Track> location);
protected:
    static std::shared_ptr<Car_Factory> f1_factory;
    static std::shared_ptr<Car_Factory> DTM_factory;
    static std::shared_ptr<Car_Factory> GT_factory;
    std::vector< std::shared_ptr<Track> > roads_to;
    std::vector< std::pair< RacingSeries, std::shared_ptr<Car_Factory> > > car_types;
    std::string track_name;
    std::string message;

};

#endif // TRACKS_H