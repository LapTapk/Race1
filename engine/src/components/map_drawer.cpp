#include "components/map_drawer.h"
#include "components/transform.h"
#include <jsoncpp/json/json.h>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <cmath>
#include "game.h"

MapCoords::MapCoords(std::string path_to_json_c) :
    path_to_json(path_to_json_c) {
    std::ifstream fin{ path_to_json };
    Json::Value json;
    fin >> json;
    for (Json::Value& v : json["points"]) {
        points.push_back({ v[0].asFloat(), v[1].asFloat() });
    }
    points.push_back(points[0]);
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

void MapCoords::push_back(sf::Vector2f v) {
    points.pop_back();
    points.push_back(v);
    points.push_back(points[0]);
}

MapCoords::~MapCoords() {
    save();
}

MapDrawer::MapDrawer(GameObject* go, std::string path_to_json, bool write_c) :
    Component{ go }, coords{ path_to_json }, write{ write_c } {
}

void MapDrawer::draw_line(int i, sf::VertexArray& lines, sf::Vector2f a, sf::Vector2f b) {
    const Game* game{ Game::instance };
    const GameObject* camera{ game->camera->go };
    float zoomout{ game->camera->zoomout };
    std::pair<int, int> wsize{ game->conf.window_size };
    sf::Vector2f window_offset{
        wsize.first / 2, wsize.second / 2
    };
    sf::Vector2f pos{a - b};
    pos /= zoomout;
    double alpha = camera->transform->global_rot() / 180.0f * M_PI;
    sf::Vector2f rot_pos{ pos.x * cos(alpha) - pos.y * sin(alpha),
    pos.y * cos(alpha) + pos.x * sin(alpha) };
    rot_pos.y *= -1;
    rot_pos += window_offset;
    lines[i].position = rot_pos;
    lines[i].color = sf::Color::Yellow;
}

void MapDrawer::draw() {
    Game* game{ Game::instance };
    int count = coords.points.size();
    sf::VertexArray lines{ sf::LinesStrip, count };
    for (int i = 0; i < count; i++) {
        draw_line(i, lines, coords.points[i], game->camera->go->transform->global_pos());
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
        coords.push_back(get_pos());
        coords.save();
    }

    draw();
}