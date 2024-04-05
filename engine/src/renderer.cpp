#include "renderer.h"
#include "transform.h"
#include "game.h"

Renderer::Renderer(GameObject* go, std::string path_to_img) : Component(go) {
    texture.loadFromFile(path_to_img);
    sprite.setTexture(texture);
}

void Renderer::update() {
    Game* game{ Game::instance };
    Transform* transform{ go->transform };

    sf::Vector3f pos3{ transform->global_pos() };
    sf::Vector2u tsize = texture.getSize();
    sf::Vector3f camera_pos{ game->camera->transform->global_pos() };
    float posx = pos3.x + game->conf.window_size.first / 2 -
        tsize.x / 2 - camera_pos.x;
    float posy = pos3.y + game->conf.window_size.second / 2 -
        tsize.y / 2 - camera_pos.y;
    sprite.setPosition(posx, posy);

    sf::Vector2f scale{ transform->global_scale() };
    float camera_height_coef{
        1.0f * game->conf.default_camera_offset / game->camera->transform->position.z };
    sprite.setScale(scale.x * camera_height_coef, scale.y * camera_height_coef);

    sprite.setRotation(transform->global_rot());

    game->window.draw(sprite);
}
