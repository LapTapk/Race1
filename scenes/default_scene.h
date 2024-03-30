#ifndef DEFAULT_SCENE_H
#define DEFAULT_SCENE_H

#include "game_object.h"

GameObject* create_defualt_scene() {
    GameObject* scene{ new GameObject(nullptr) };
    GameObject* penguin{ new GameObject(scene) };
    
}

#endif
