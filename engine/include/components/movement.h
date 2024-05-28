#ifndef MOVER_H
#define MOVER_H

#include <SFML/Graphics.hpp>
#include "game_object.h"

class Movement : public Component {
public:
    void update() override;
    Movement(GameObject* go);
    sf::Vector2f vector{sf::Vector2f{0, 0}};
    void set_vector(sf::Vector2f dir, float speed);
};

#endif