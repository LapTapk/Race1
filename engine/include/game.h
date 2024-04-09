#ifndef GAME_H
#define GAME_H

#include "event_manager.h"
#include "game_object.h"
#include "game_conf.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

class Game {
public:
    static Game* instance;
    sf::Clock clock;
    std::unique_ptr<GameObject> scene;
    GameObject* camera;
    sf::RenderWindow window;
    EventManager event_manager;
    GameConf conf;
    bool running = false;
    void run();
    float get_delta_time();
    Game(GameConf conf, GameObject* scene, GameObject* camera);
    ~Game();
private:
    float delta_time;
    void iteration();
};

#endif 