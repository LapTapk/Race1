#ifndef MOVER_INPUT_H
#define MOVER_INPUT_H

#include "game_object.h"
#include "mover.h"

class WASDMoverInput : public Component {
public:
    WASDMoverInput(GameObject* go, Mover* mover);
    void update() override;
private:
    Mover* mover;
};

#endif