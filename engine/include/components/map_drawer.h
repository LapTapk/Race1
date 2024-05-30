#ifndef MAP_DRAWER_H
#define MAP_DRAWER_H

#include <string>
#include <vector>
#include "game_object.h"
#include <jsoncpp/json/json.h>
#include <SFML/Graphics.hpp>

class MapCoords {
public:
    MapCoords(std::string path_to_json);
    std::vector<sf::Vector2f> points;
    Json::Value to_json();
    void save();
    void push_back(sf::Vector2f v);
    ~MapCoords();
private:
    std::string path_to_json;
};

class MapDrawer : public Component {
public:
    MapDrawer(GameObject* go,
        std::string path_to_json, bool write);
    void update() override;
    bool write;
    MapCoords coords;
    void draw();
private:
};

#endif