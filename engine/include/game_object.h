#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <vector>
#include "component.h"
#include "transform.h"

class GameObject {
public:
    GameObject* parent;
    std::vector<Component*> components;
    std::vector<GameObject*> children;
    Transform* transform;
    void update();
    void remove_cmp(Component* cmp);
    GameObject(GameObject* parent);
    ~GameObject();
};
#endif