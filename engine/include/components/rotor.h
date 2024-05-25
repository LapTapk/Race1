#ifndef ROTOR_H
#define ROTOR_H

#include "game_object.h"

class Rotor : public Component {
public:
    Rotor(GameObject* go);
    void update() override;
};

#endif