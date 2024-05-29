#ifndef ROAD_CHECK_H
#define ROAD_CHECK_H

#include "game_object.h"
#include "components/map_drawer.h"

class CarMovement;

class RoadCheck : public Component {
public:
    RoadCheck(GameObject* go,
        MapCoords& outborders, MapCoords& inborders);
    MapCoords& outborders, & inborders;
    bool is_on_road(CarMovement* mover);
};

#endif