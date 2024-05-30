#include "utils.h"
#include "game.h"
#include "game_object.h"
#include "components/transform.h"
#include <cmath>

line::line(sf::Vector2f a_c, sf::Vector2f b_c) :
    a{ a_c }, b{ b_c } {
}

bool line::ccw(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c) {
    return (c.y - a.y) * (b.x - a.x) > (b.y - a.y) * (c.x - a.x);
}

bool line::are_intersecting(line& other) {
    return ccw(a, other.a, other.b) != ccw(b, other.a, other.b) &&
        ccw(a, b, other.a) != ccw(a, b, other.b);
}

void draw_lines(std::vector<sf::Vector2f>& coords) {
    Game* game{ Game::instance };
    int count = coords.size();
    sf::VertexArray lines{ sf::LinesStrip, count };
    for (int i = 0; i < count; i++) {
        const Game* game{ Game::instance };
        const GameObject* camera{ game->camera->go };
        float zoomout{ game->camera->zoomout };
        std::pair<int, int> wsize{ game->conf.window_size };
        sf::Vector2f window_offset{
            wsize.first / 2, wsize.second / 2
        };
        sf::Vector2f pos{
            coords[i] - game->camera->go->transform->global_pos()
        };
        pos /= zoomout;
        double alpha = camera->transform->global_rot() / 180.0f * M_PI;
        sf::Vector2f rot_pos{ pos.x * cos(alpha) - pos.y * sin(alpha),
        pos.y * cos(alpha) + pos.x * sin(alpha) };
        rot_pos.y *= -1;
        rot_pos += window_offset;
        lines[i].position = rot_pos;
        lines[i].color = sf::Color::Yellow;
    }
    game->window.draw(lines);
}

sf::Vector2f get_mpos() {
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