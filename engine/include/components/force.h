#ifndef FORCE_H
#define FORCE_H

#include "game_object.h"
#include "mover.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Force : public Component {
public:
    Mover* mover;
    std::vector<sf::Vector2f> accelerations;
    Force(GameObject* go, Mover* mover);
    void update() override;
};

#endif