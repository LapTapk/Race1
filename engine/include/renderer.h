#ifndef RENDERER_H
#define RENDERER_H

#include "game_object.h"
#include <string>
#include <SFML/Graphics.hpp>

class Renderer : public Component {
public:
    Renderer(GameObject* go, std::string path_to_img);
    void update() override;
private:
    sf::Sprite sprite;
    sf::Texture texture;
};

#endif