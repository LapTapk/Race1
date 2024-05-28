#ifndef FORCE_H
#define FORCE_H

#include "game_object.h"
#include "movement.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Force : public Component {
public:
    Movement* mover;
    std::vector<sf::Vector2f> accelerations;
    Force(GameObject* go, Movement* mover);
    void update() override;
};

#endif