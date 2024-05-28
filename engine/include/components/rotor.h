#ifndef ROTOR_H
#define ROTOR_H

#include "game_object.h"

class Rotor : public Component {
public:
    Rotor(GameObject* go);
    float get_rotation();
    void update() override;
};

#endif