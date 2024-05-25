#include "components/mover.h"
#include "game.h"
#include "components/transform.h"
#include <iostream>
#include <cmath>

Mover::Mover(GameObject* go, sf::Vector2f vector_c) :
    Component(go), vector(vector_c) {}

void Mover::update() {
    float delta_time{ Game::instance->get_delta_time() };
    sf::Vector2f delta{ vector * delta_time };
    go->transform->position += delta;
}
