#ifndef GAME_H
#define GAME_H

#include "event_manager.h"
#include "game_object.h"
#include "game_conf.h"
#include <SFML/Graphics.hpp>
#include <string>

class Game {
public:
    static Game* instance;
    sf::Clock clock;
    GameObject* scene;
    GameObject* camera;
    sf::RenderWindow window;
    EventManager event_manager;
    GameConf conf;
    bool running = false;
    void run();
    Game(GameConf conf, GameObject* scene, GameObject* camera);
    ~Game();
private:
    void iteration();
};

#endif 