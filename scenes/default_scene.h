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
    penguin->transform->position.x = 100;
    camera = new GameObject(scene);
    camera->transform->position = sf::Vector3f(0, 0, 10);
    new Renderer(penguin, "../assets/penguin.png");
    Mover* mover{ new Mover(penguin, 150) };
    new WASDMoverInput(penguin, mover);
    GameObject* penguin1{ new GameObject(scene) };
    penguin1->transform->position.x = -100;
    new Renderer(penguin1, "../assets/penguin.png");
}

#endif
