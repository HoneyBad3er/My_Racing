#include "game.h"
#include <memory>
#include <limits>
#include <cstdlib>
#include "concreate_race.h"
#include "tmp_namespaces.h"

Game::Game() : greeting("Здравствуй гонщик, приветствуем тебя\nНазови своё имя: "),
               team(std::make_shared<RacingTeam>()) {

    std::vector<RacingSeries> SilverstoneCars;
    std::vector<RacingSeries> SpaFrancorchampsCars;
    std::vector<RacingSeries> ZandvoortCars;
    std::vector<RacingSeries> AlbertParkCars;
    SilverstoneCars.push_back(Formula1);
    SilverstoneCars.push_back(DTM);
    SilverstoneCars.push_back(GT);
    SpaFrancorchampsCars.push_back(Formula1);
    ZandvoortCars.push_back(DTM);
    AlbertParkCars.push_back(GT);

    current_track = std::make_shared<Track>("Silverstone", 
                                            " мы на треке Сильверстоун",
                                            SilverstoneCars); 
    tracks.push_back(current_track);
    tracks.push_back(std::make_shared<Track>("Spa-Francorchamps", 
                                             " мы на треке Спа",
                                             SpaFrancorchampsCars));
    tracks.push_back(std::make_shared<Track>("Zandvoort", 
                                             "  мы на треке Зандворт",
                                             ZandvoortCars));
    tracks.push_back(std::make_shared<Track>("AlbertPar", 
                                             "  мы на треке Альберт-Парк",
                                             AlbertParkCars));
    tracks[0]->AddRoad(tracks[1]);
    tracks[0]->AddRoad(tracks[2]);
    tracks[0]->AddRoad(tracks[3]);
    tracks[1]->AddRoad(tracks[0]);
    tracks[1]->AddRoad(tracks[2]);
    tracks[1]->AddRoad(tracks[3]);
    tracks[2]->AddRoad(tracks[0]);
    tracks[2]->AddRoad(tracks[1]);
    tracks[2]->AddRoad(tracks[3]);
    tracks[3]->AddRoad(tracks[0]);
    tracks[3]->AddRoad(tracks[1]);
    tracks[3]->AddRoad(tracks[2]);
}

Game::~Game() {}

std::shared_ptr<Car> Game::Greeting() {
    std::cout << greeting;
    std::string name;

    while (true) {
        std::cin >> name;
        if (name == "") {
            std::cout << "Ну же, не стесняйся, представься)\n";
        }
        else {
            user_name = name;
            break;
        }
    }
    return std::make_shared<GT_Car>();
}

void Game::NextTrack() {
    const std::vector< std::shared_ptr<Track> >& tracks = current_track->GetRoads();

    std::cout << user_name << ", какой трек будет следующим?\n";
    for (size_t i = 0; i < tracks.size(); ++i) {
        std::cout << i << " " << tracks[i]->GetName() << "\n";
    }

    std::string track_num_s = "void";
    size_t track_num = std::numeric_limits<size_t>::max();
    while (true) {
        std::cin >> track_num_s;
        try{
            track_num = std::stoi(track_num_s);
        }
        catch(const std::invalid_argument& ex) {
            std::cout << "Такого трека нет!\n";
            continue;
        }
        if (track_num < tracks.size()) {
            current_track = tracks[track_num];
            std::shared_ptr<Car> car = tracks[track_num]->Get_Car();
            std::cout << "На пути вам встретился болид " << car->GetType() << "\n";
            std::cout << user_name << ", выберите тип гонки:\n";
            std::cout << 0 << " - Дрэг; " << 1 << " - Кольцо;" << "\n";
            std::string command_s = "void";
            size_t command = std::numeric_limits<size_t>::max();
            while (true) {
                std::cin >> command_s;
                try{
                    command = std::stoi(command_s);
                }
                catch(const std::invalid_argument& ex) {
                    std::cout << "Неверная команда\n";
                    continue;
                }
                if (command > 1) {
                    std::cout << "Неверная команда\n";
                }
                else {
                    team->PrintTeam();

                    std::string car_num_s = "void";
                    size_t car_num = std::numeric_limits<size_t>::max();
                    while (true) {
                        std::cin >> car_num_s;
                        try{
                            car_num = std::stoi(car_num_s);
                        }
                        catch(const std::invalid_argument& ex) {
                            std::cout << "Неверная команда\n";
                            continue;
                        }
                        if (car_num >= team->Get_quantity()) {
                            std::cout << "Попробуй снова: ";
                            continue;
                        }
                        else {
                            break;
                        }
                    }
                    
                    std::shared_ptr<Car> chosedCar = team->GetCar(car_num);

                    if (command == 0) {
                        DragRace race(chosedCar, car);
                        if (race.Run_Race()) {
                            std::cout << "Вы победили\n";
                            team->AddCar(car);
                        }
                        else {
                            std::cout << "Вы проиграли\n";
                            team->RemoveCar(car_num);
                        } 
                    }

                    else if (command == 1) {
                         RingRace race(chosedCar, car);
                        if (race.Run_Race()) {
                            std::cout << "Вы победили\n";
                            team->AddCar(car);
                        }
                        else {
                            std::cout << "Вы проиграли\n";
                            team->RemoveCar(car_num);
                        } 
                    }
                    break;
                }
            }
            break;
        }
        std::cout << "Такого трека нет)\n";
    }
    
}

bool Game::GameProcess() {
    std::cout << user_name << " мы на треке Сильверстоун\n";
    while (team->Get_quantity() > 0) {
        NextTrack();
        if (team->Get_quantity() == 0) {
            break;
        }
        std::cout << "Вы можете зайти на пит-стоп!" << "\n";
        std::cout << 0 << " - В гараж; " << 1 << " - Продолжить гонять;" << "\n"; 
        std::string code_s = "void";
        size_t code = 401;
        while (true) {
            std::cin >> code_s;
            try{
                code = std::stoi(code_s);
            }
            catch(const std::invalid_argument& ex) {
                std::cout << "Неверная команда\n";
                continue;
            }
            if (code == 1) {
                break;
            }
            else if (code == 0) {
                team->PrintTeam();
                std::string car_num_s = "void";
                size_t car_num = std::numeric_limits<size_t>::max();
                while (true) {
                    std::cin >> car_num_s;
                    try{
                        car_num = std::stoi(car_num_s);
                    }
                    catch(const std::invalid_argument& ex) {
                        std::cout << "Неверная команда\n";
                        continue;
                    }
                    if (car_num >= team->Get_quantity()) {
                        std::cout << "Попробуй снова: ";
                        continue;
                    }
                    else {
                        break;
                    }
                    Pit::GoPit(team->GetCar(car_num));
                    break;
                }
                break;
            }
        }
    }

    return false;
}

void Game::Run() {
    team->AddCar( Greeting() );
    if (GameProcess()) {
        std::cout << "Поздравляю тебя, " << user_name << ", ты победил!\n";
    }
    else {
        std::cout << "К сожалению, " << user_name << ", ты проиграл!\n";
    }
     
}

