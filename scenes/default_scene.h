#ifndef DEFAULT_SCENE_H
#define DEFAULT_SCENE_H

#include "game_object.h"
#include "transform.h"
#include "mover.h"
#include "mover_input.h"
#include "renderer.h"

void create_defualt_scene(GameObject*& scene, GameObject*& camera) {
    scene = new GameObject(nullptr);
    GameObject* penguin{ new GameObject(scene) };
    camera = new GameObject(scene);
    camera->transform->position.z = 10;
    camera->transform->rotation = 90;
    new Renderer(penguin, "../assets/penguin.png");
    Mover* mover{ new Mover(penguin, 150) };
    new WASDMoverInput(penguin, mover);
}

#endif
