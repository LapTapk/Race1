#include "component.h"
#include "game_object.h"

Component::Component(GameObject* go_c) {
    go = go_c;
    go->components.push_back(this);
}
