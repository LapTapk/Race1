#include "components/renderer.h"
#include "components/transform.h"
#include "game.h"
#include <cmath>

Renderer::Renderer(GameObject* go, std::string path_to_img) : Component(go) {
    texture.loadFromFile(path_to_img);
    sprite.setTexture(texture);
    sf::Vector2f tzise{ texture.getSize() };
    sprite.setOrigin(tzise.x / 2, tzise.y / 2);
}

void Renderer::update() {
    Game* game{ Game::instance };
    Transform* transform{ go->transform };
    Camera* camera{ game->camera };

    int camera_rot{ camera->go->transform->global_rot() };
    int rot{ transform->global_rot() - camera_rot };
    sprite.setRotation(rot);

    sf::Vector2f pos{ transform->global_pos() };
    pos.y *= -1.0f;

    sf::Vector2f camera_pos{ camera->go->transform->global_pos() };
    camera_pos.y *= -1.0f;

    sf::Vector2f radius{ pos - camera_pos };
    radius /= camera->zoomout;
    double alpha = camera_rot / 180.0f * M_PI;
    sf::Vector2f rot_pos{ radius.x * cos(alpha) - radius.y * sin(alpha),
        radius.y * cos(alpha) + radius.x * sin(alpha) };

    sf::Vector2f window_offset(
        game->conf.window_size.first / 2, game->conf.window_size.second / 2);

    rot_pos += window_offset;
    sprite.setPosition(rot_pos);


    sf::Vector2f scale{ transform->global_scale() };
    scale /= camera->zoomout;
    sprite.setScale(scale);

    game->window.draw(sprite);
}
