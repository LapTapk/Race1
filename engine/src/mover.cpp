#include "mover.h"
#include "game.h"
#include "transform.h"
#include <iostream>
#include <cmath>

Mover::Mover(GameObject* go, float speed_c) :
    Component(go), speed(speed_c) {}

void Mover::update() {
    float delta_time{ Game::instance->get_delta_time() };
    sf::Vector2f delta2{ direction * speed * delta_time };
    sf::Vector3f delta(delta2.x, delta2.y, 0);
    go->transform->position += delta;
}

void Mover::set_direction(int x, int y) {
    set_direction(sf::Vector2f(x, y));
}

void Mover::set_direction(sf::Vector2f dir) {
    if(dir.x == 0 || dir.y == 0) {
        direction = dir;
        return;
    }
    float len{sqrt(dir.x * dir.x + dir.y * dir.y)};
    dir /= len;
    direction = dir;
}

sf::Vector2f Mover::get_direction() {
    return direction;
}
