#include "game_object.h"
#include "transform.h"
#include <algorithm>
#include <vector>

GameObject::GameObject() : GameObject(nullptr) {};

GameObject::GameObject(GameObject* parent_c) {
    parent = parent_c;
    if (parent != nullptr) {
        parent->children.push_back(this);
    }
    transform = new Transform(this);
}

void update_rec(GameObject* cur) {
    for (GameObject* go : cur->children) {
        update_rec(go);
    }

    for (std::unique_ptr<Component>& cmp : cur->components) {
        cmp->update();
    }
}

void GameObject::update() {
    update_rec(this);
}

void GameObject::remove_cmp(std::unique_ptr<Component> cmp) {
    if (dynamic_cast<Transform*>(cmp.get()) != nullptr) {
        return;
    }

    auto i{ std::find(components.begin(), components.end(), cmp) };
    components.erase(i);
}

GameObject::~GameObject() {
    for (GameObject* go : children) {
        delete go;
    }

    for (std::unique_ptr<Component>& cmp : components) {
        cmp.release();
    }
}

Component::Component(std::shared_ptr<GameObject> go_c) {
    go = go_c;
    go->components.push_back(std::unique_ptr<Component>(this));
}