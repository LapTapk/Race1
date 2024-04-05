#include "test_cmp.h"
#include "game.h"
#include "transform.h"
#include "game_object.h"
#include <SFML/Graphics.hpp>
#include <iostream>

TestCmp::TestCmp(GameObject* go) : Component(go) {

}

void TestCmp::update() {
    for(sf::Event& e : Game::instance->event_manager.events) {
        if(e.key.code == sf::Keyboard::A) {
            go->transform->position.x -= 10;
        }
        else if(e.key.code == sf::Keyboard::D) {
            go->transform->position.x += 10;
        }
        else if(e.key.code == sf::Keyboard::W) {
            go->transform->position.y -= 10;
        }
        else if(e.key.code == sf::Keyboard::S) {
            go->transform->position.y += 10;
        }
    }
}