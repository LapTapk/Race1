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
    new MapDrawer{ go, path, write };
    return go;
}

void create_defualt_scene(GameObject*& scene, Camera*& camera) {
    scene = new GameObject{ nullptr };
    GameObject* car{ new GameObject{scene} };
    Movement* mover{ new Movement{car} };
    CarConf car_conf{ 500, 30, 1, 3, 0.1 };
    Force* force{ new Force{car, mover} };
    CarMovement* car_mover{ new CarMovement{car,force, car_conf} };
    car_mover->decelerate = false;
    create_map_drawer(scene, "../configs/map1.json", false);
    create_map_drawer(scene, "../configs/map2.json", true);
    GameObject* camera_go{ new GameObject{car} };
    camera = new Camera{ camera_go, 3 };
    GameObject* go{ new GameObject{car} };
    new Renderer{ go, "../assets/wheel.png" };
    new Renderer{ car, "../assets/penguin.png" };
    Rotor* rotor{ new Rotor{ go } };
    go->transform->position = sf::Vector2f{700, -700};
    new WheelCarInput{ car, rotor, car_mover };

}

#endif
