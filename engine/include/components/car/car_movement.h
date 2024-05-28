#ifndef CAR_MOVEMENT_H
#define CAR_MOVEMENT_H

#include "game_object.h"
#include "components/force.h"
#include "components/car/car_conf.h"
#include <SFML/Graphics.hpp>

class CarMovement : public Component {
private:
    Force* force;
    sf::Vector2f* vdeceleration, * vacceleration;
    sf::Vector2f direction;

public:
    CarMovement(GameObject* go, Force* force, CarConf conf);
    CarConf conf;
    bool decelerate{ false }, move{ false };
    void set_dir(sf::Vector2f dir);
    sf::Vector2f get_dir();
    void update() override;
};

#endif