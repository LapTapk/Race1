#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <vector>
#include <memory>

class Transform;
class Component;

class GameObject {
public:
    GameObject* parent;
    std::vector<std::unique_ptr<Component>> components;
    std::vector<std::unique_ptr<GameObject>> children;
    Transform* transform;
    void update();
    void remove_cmp(Component* cmp);
    GameObject();
    GameObject(GameObject* parent);
    ~GameObject();
};

class Component {
public:
    GameObject* go;
    virtual void update() {};
    Component(GameObject* go);
};
#endif