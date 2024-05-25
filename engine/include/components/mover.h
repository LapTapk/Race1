#ifndef MOVER_H
#define MOVER_H

#include <SFML/Graphics.hpp>
#include "game_object.h"

class Mover : public Component {
public:
    void update() override;
    Mover(GameObject* go, sf::Vector2f vector);
    sf::Vector2f vector{sf::Vector2f(0, 0)};
};

#endif