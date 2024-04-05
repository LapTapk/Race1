#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <SFML/Graphics.hpp>

#include "game_object.h"

class Transform : public Component {
public:
    sf::Vector3f position = sf::Vector3f(0, 0, 0);
    sf::Vector3f global_pos();
    sf::Vector2f scale = sf::Vector2f(1, 1);
    sf::Vector2f global_scale();
    float rotation = 0;
    float global_rot();
    Transform(GameObject* go);
};

#endif