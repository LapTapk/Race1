#ifndef CAR_MOVEMENT_H
#define CAR_MOVEMENT_H

#include "game_object.h"
#include "components/force.h"
#include "components/car/car_conf.h"
#include "components/road_check.h"
#include <SFML/Graphics.hpp>

class CarMovement : public Force {
private:
    sf::Vector2f* vdeceleration, * vacceleration;
    sf::Vector2f direction;

public:
    CarMovement(GameObject* go, CarConf conf, 
        RoadCheck* checker);
    CarConf conf;
    bool decelerate{ false }, move{ false };
    void set_dir(sf::Vector2f dir);
    sf::Vector2f get_dir();
    void update() override;
    RoadCheck* checker;
};

#endif