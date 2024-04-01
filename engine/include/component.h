#ifndef COMPONENT_H
#define COMPONENT_H

class GameObject;

class Component {
public:
    GameObject* go;
    virtual void update() {};
    Component(GameObject* go);
};
#endif