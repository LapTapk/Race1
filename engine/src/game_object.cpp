#include "transform.h"
#include "game_object.h"
#include "component.h"
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

    for (Component* cmp : cur->components) {
        cmp->update();
    }
}

void GameObject::update() {
    update_rec(this);
}

void GameObject::remove_cmp(Component* cmp) {
    if (dynamic_cast<Transform*>(cmp) != nullptr) {
        return;
    }

    auto i{ std::find(components.begin(), components.end(), cmp) };
    components.erase(i);
    delete cmp;
}

GameObject::~GameObject() {
    for (GameObject* go : children) {
        delete go;
    }

    for (Component* cmp : components) {
        delete cmp;
    }
}