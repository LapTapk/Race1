#include "components/rotor.h"
#include "game.h"
#include "components/transform.h"
#include <SFML/Graphics.hpp>

Rotor::Rotor(GameObject* go) : Component(go) {}

void Rotor::update() {
    sf::RenderWindow& window{ Game::instance->window };
    int mposx{ sf::Mouse::getPosition(window).x };
    int center{ window.getSize().x / 2 };
    int wrd{ Game::instance->conf.wheel_rot_delta };
    int diff{ mposx - center };
    if (diff != 0) {
        diff = std::min(abs(diff), wrd) * abs(diff) / diff;
    }
    float coef{ 1.0f * diff / wrd };

    go->transform->rotation = 90 * coef;
}