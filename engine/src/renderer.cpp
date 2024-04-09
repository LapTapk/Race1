#include "renderer.h"
#include "transform.h"
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

    int camera_rot{ game->camera->transform->global_rot() };
    int rot{ transform->global_rot() + camera_rot };
    sprite.setRotation(rot);

    sf::Vector3f pos3{ transform->global_pos() };
    sf::Vector2f pos2(pos3.x, pos3.y);

    sf::Vector3f camera_pos3{ game->camera->transform->global_pos() };
    sf::Vector2f camera_pos2(camera_pos3.x, camera_pos3.y);

    sf::Vector2f window_offset(
        game->conf.window_size.first / 2, game->conf.window_size.second / 2);
    sf::Vector2f pos{ pos2 - camera_pos2 + window_offset };
    sprite.setPosition(pos);


    sf::Vector2f scale{ transform->global_scale() };
    float camera_height_coef{
        1.0f * game->conf.default_camera_offset / game->camera->transform->position.z };
    sprite.setScale(scale.x * camera_height_coef, scale.y * camera_height_coef);

    game->window.draw(sprite);
}
