#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <SFML/Graphics.hpp>

#include "component.h"

class Transform : public Component {
public:
    sf::Vector3f position = sf::Vector3f(0, 0, 0);
    sf::Vector2f scale = sf::Vector2f(1, 1);
    float rotation = 0;
    Transform(GameObject* go) : Component(go) {};
};

#endif