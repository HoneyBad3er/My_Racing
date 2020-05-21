#ifndef GAME_H
#define GAME_H
#include <memory>
#include <string>
#include <vector>
#include "car.h"
#include "racing_team.h"
#include "tracks.h"


class Game {
public:
    Game();
    ~Game();
    void Run();
private:
    std::string greeting;
    std::string user_name;
    std::shared_ptr<RacingTeam> team;
    std::vector< std::shared_ptr<Track> > tracks;
    std::shared_ptr<Track> current_track;
    std::shared_ptr<Car> Greeting();
    bool GameProcess();
    void NextTrack();
};

#endif // CARFACTORY_H