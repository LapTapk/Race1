#include "test_cmp.h"
#include "component.h"
#include "game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

TestCmp::TestCmp(GameObject* go) : Component(go) {
    
}

void TestCmp::update() {
    for(sf::Event& e : Game::instance->event_manager.events) {
        if (e.type == sf::Event::KeyPressed) {
            std::cout << e.key.code << std::endl;
        }
    }
}