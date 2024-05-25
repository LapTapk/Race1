#include "components/map_drawer.h"
#include "components/transform.h"
#include <jsoncpp/json/json.h>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "game.h"

MapCoords::MapCoords(std::string path_to_json_c) :
    path_to_json(path_to_json_c) {
    std::ifstream fin{ path_to_json };
    Json::Value json;
    fin >> json;
    for (Json::Value& v : json["points"]) {
        points.push_back({ v[0].asFloat(), v[1].asFloat() });
    }
}

Json::Value MapCoords::to_json() {
    Json::Value pts;
    Json::Value vec{ Json::arrayValue };
    for (sf::Vector2f& p : points) {
        Json::Value json_p{ Json::arrayValue };
        json_p.append(p.x);
        json_p.append(p.y);
        vec.append(json_p);
    }
    pts["points"] = vec;
    return pts;
}

void MapCoords::save() {
    std::ofstream fout
    { path_to_json, std::ofstream::out | std::ofstream::trunc };
    fout << to_json();
}

MapCoords::~MapCoords() {
    save();
}

MapDrawer::MapDrawer(GameObject* go, std::string path_to_json, bool write_c) :
    Component{go}, coords{path_to_json}, write{write_c} {
}

void MapDrawer::draw() {
    Game* game{ Game::instance };
    int count = coords.points.size();
    sf::VertexArray lines{ sf::LinesStrip, count };
    for (int i = 0; i < count; i++) {
        float zoomout{ game->camera->zoomout };
        std::pair<int, int> wsize{ game->conf.window_size };
        sf::Vector2f window_offset{
            wsize.first / 2 * zoomout, wsize.second / 2 * zoomout
        };
        sf::Vector2f pos{
            coords.points[i] - game->camera->go->transform->position
            + window_offset
        };
        pos /= zoomout;
        lines[i].position = pos;
        lines[i].color = sf::Color::Yellow;
    }
    game->window.draw(lines);
}

bool called_left_click() {
    for (sf::Event& e : Game::instance->event_manager.events) {
        bool pressed = e.type == sf::Event::MouseButtonPressed;
        bool left = e.mouseButton.button == sf::Mouse::Left;
        if (pressed && left) {
            return true;
        }
    }
    return false;
}

sf::Vector2f get_pos() {
    Game* game{ Game::instance };
    sf::Vector2f mpos{ sf::Mouse::getPosition(game->window) };
    float zoomout{ game->camera->zoomout };
    mpos *= zoomout;
    mpos += game->camera->go->transform->position;

    std::pair<int, int> wsize{ game->conf.window_size };
    sf::Vector2f window_offset{
        wsize.first / 2 * zoomout, wsize.second / 2 * zoomout
    };
    mpos -= window_offset;
    return sf::Vector2f{ mpos.x, mpos.y };
}

void MapDrawer::update() {
    if (write && called_left_click()) {
        coords.points.push_back(get_pos());
        coords.save();
    }

    draw();
}