#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H 

#include <SFML/Graphics.hpp>

class EventManager {
    std::vector<sf::Event> events;
    void update();
};

#endif