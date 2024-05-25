#ifndef DEFAULT_SCENE_H
#define DEFAULT_SCENE_H

#include "game_object.h"
#include "components.h"
#include <string>

GameObject* create_penguin(GameObject* scene) {
    GameObject* go{ new GameObject{scene} };
    Renderer* rend{ new Renderer{go, "../assets/penguin.png"} };
    go->transform->position = sf::Vector2f{ 1000, 1000 };
    return go;
}

GameObject* create_map_drawer(GameObject* scene, std::string path, bool write) {
    GameObject* go{ new GameObject{scene} };
    new MapDrawer{go, path, write};
    return go;
}

void create_defualt_scene(GameObject*& scene, Camera*& camera) {
    scene = new GameObject{ nullptr };
    GameObject* camera_go{ new GameObject{scene} };
    camera = new Camera{ camera_go, 10 };
    create_map_drawer(scene, "../configs/map1.json", false);
    create_map_drawer(scene, "../configs/map2.json", true);
}

#endif
