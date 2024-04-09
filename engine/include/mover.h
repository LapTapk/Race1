#ifndef MOVER_H
#define MOVER_H

#include <SFML/Graphics.hpp>
#include "game_object.h"

class Mover : public Component {
public:
    float speed;
    void update() override;
    void set_direction(sf::Vector2f dir);
    void set_direction(int x, int y);
    sf::Vector2f get_direction();
    Mover(GameObject* go, float speed);
private:
    sf::Vector2f direction{sf::Vector2f(0, 0)};
};

#endif