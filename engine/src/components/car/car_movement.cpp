#include "components/car/car_movement.h"
#include "components/transform.h"
#include <cmath>
#include <iostream>

CarMovement::CarMovement(GameObject* go, Force* force_c, CarConf conf_c) :
    Component{ go }, force{ force_c }, conf{ conf_c } {
    force->accelerations.push_back(sf::Vector2f{ 0, 0 });
    force->accelerations.push_back(sf::Vector2f{ 0, 0 });
    vacceleration = &force->accelerations[0];
    vdeceleration = &force->accelerations[1];
}


float len(sf::Vector2f v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

sf::Vector2f get_unit_v(sf::Vector2f v) {
    float l{ len(v) };
    if (l == 0) {
        return v;
    }
    return v / l;
}

void CarMovement::set_dir(sf::Vector2f dir) {
    direction = get_unit_v(dir);
}

sf::Vector2f CarMovement::get_dir() {
    return direction;
}

void CarMovement::update() {
    sf::Vector2f& vector{ force->mover->vector };
    if (len(vector) > 1) {
        go->transform->rotation += conf.rotation_delta * direction.x;
    }

    float angle{ go->transform->global_rot() / 180.0f * M_PI };
    sf::Vector2f forward{ sin(angle), cos(angle) };
    vector = forward * len(vector);

    if (move) {
        *vacceleration = forward * conf.acceleration;
    }
    else {
        *vacceleration = sf::Vector2f{ 0, 0 };
    }

    float ms{ conf.max_speed };
    if (decelerate) {
        *vacceleration *= conf.decelerate_coef;
        ms *= conf.decelerate_coef;
    }

    *vdeceleration =
        conf.friction * get_unit_v(-vector);
    if (len(vector) >= ms) {
        *vdeceleration += -*vacceleration;
    }
}
