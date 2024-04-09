#include "game.h"
#include <fstream>
#include <stdexcept>
#include <thread>
#include <chrono>
#include <memory>

Game::Game(GameConf conf_c, GameObject* scene_c, GameObject* camera_c) :
    conf(conf_c),
    window(sf::VideoMode(conf_c.window_size.first, conf_c.window_size.second), conf_c.title),
    event_manager(),
    scene(std::unique_ptr<GameObject>(scene_c)),
    camera(camera_c),
    clock() {
    if(instance != nullptr) {
        throw std::runtime_error("There must be only one instance of class Game!");
    }
    instance = this;
}

void Game::iteration() {
    window.clear();

    event_manager.update();

    for (sf::Event e : event_manager.events) {
        if (e.type == sf::Event::Closed) {
            running = false;
        }
    }

    scene->update();

    window.display();
    int sec = std::max(0, 1000 / conf.fps - clock.getElapsedTime().asMilliseconds());
    std::this_thread::sleep_for(std::chrono::milliseconds(sec));
    delta_time = clock.getElapsedTime().asSeconds() + sec;
    clock.restart();
}

void Game::run() {
    running = true;
    while (running) {
        iteration();
    }
    window.close();
}


Game::~Game() {
    scene.reset();
}

float Game::get_delta_time() {
    return delta_time;
}

Game* Game::instance{nullptr};