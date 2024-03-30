#ifndef COMPONENT_H
#define COMPONENT_H

#include "game_object.h"

class Component {
public:
    GameObject* go;
    virtual void update();
    Component(GameObject* go);
};
#endif