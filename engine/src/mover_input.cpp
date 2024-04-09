#include "mover_input.h"
#include "game.h"
#include "mover.h"
#include <iostream>
#include <SFML/Graphics.hpp>

WASDMoverInput::WASDMoverInput(GameObject* go, Mover* mover_c) :
    Component(go), mover(mover_c) {}

void WASDMoverInput::update() {
    int x{ 0 }, y{ 0 };
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        x = -1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        x = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        y = -1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        y = 1;
    }
    mover->set_direction(x, y);
}
