#ifndef WHEEL_CAR_INPUT_H
#define WHEEL_CAR_INPUT_H

#include "game_object.h"
#include "components/rotor.h"
#include "components/car/car_movement.h"

class WheelCarInput : public Component {
private:
    Rotor* rotor;
    CarMovement* mover;
public:
    WheelCarInput(GameObject* go, Rotor* rotor, CarMovement* mover);
    void update() override;
};

#endif