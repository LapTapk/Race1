#ifndef DEFAULT_SCENE_H
#define DEFAULT_SCENE_H

#include "game_object.h"
#include "transform.h"
#include "test_cmp.h"
#include "renderer.h"

void create_defualt_scene(GameObject*& scene, GameObject*& camera) {
    scene = new GameObject(nullptr);
    GameObject* penguin{ new GameObject(scene) };
    penguin->transform->position.x = 100;
    camera = new GameObject(scene);
    camera->transform->position = sf::Vector3f(0, 0, 10);
    TestCmp* test_cmp{ new TestCmp(camera) };
    Renderer* rend{ new Renderer(penguin, "../assets/penguin.png") };
    GameObject* penguin1{ new GameObject(scene) };
    penguin1->transform->position.x = -100;
    Renderer* rend1{ new Renderer(penguin1, "../assets/penguin.png") };
}

#endif
