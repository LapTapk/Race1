#include "game_object.h"
#include "game.h"
#include "components/transform.h"

Transform::Transform(GameObject* go) : Component(go) {}

sf::Vector2f Transform::global_pos() {
    GameObject* parent{ go->parent };
    if (parent == nullptr) {
        return position;
    }

    sf::Vector2f parent_gpos = parent->transform->global_pos();
    return position + parent_gpos;
}

sf::Vector2f Transform::global_scale() {
    GameObject* parent{ go->parent };
    if (parent == nullptr) {
        return scale;
    }

    sf::Vector2f parent_gscale = parent->transform->global_scale();
    return sf::Vector2f(scale.x * parent_gscale.x, scale.y * parent_gscale.y);
}

float Transform::global_rot() {
    GameObject* parent{ go->parent };
    if (parent == nullptr) {
        return rotation;
    }

    float parent_grot = parent->transform->global_rot();
    return rotation + parent_grot;
}