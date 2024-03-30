#ifndef GAME_H
#define GAME_H

#include "event_manager.h"
#include "game_object.h"
#include <SFML/Graphics.hpp>

class Game {
public:
    static Game& instance(std::pair<int, int> window_size);
    GameObject scene;
    EventManager event_manager;
    sf::RenderWindow window;
    bool running;
    void run();
private:
    Game(std::pair<int, int> window_size);
};

#endif 