#ifndef DEFAULT_SCENE_H
#define DEFAULT_SCENE_H

#include "game_object.h"
#include "test_cmp.h"

GameObject* create_defualt_scene() {
    GameObject* scene{ new GameObject(nullptr) };
    GameObject* penguin{ new GameObject(scene) };
    TestCmp* test_cmp{ new TestCmp(penguin) };
    return scene;
}

#endif
