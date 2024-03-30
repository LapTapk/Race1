#ifndef RENDERER_H
#define RENDERER_H

#include "component.h"
#include <string>
#include <SFML/Graphics.hpp>

class Renderer : public Component {
    Renderer(GameObject* go, std::string path_to_img);
    void update() override;
};

#endif