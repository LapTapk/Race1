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
    GameObject* map_drawer_go{ new GameObject{scene} };
    MapDrawer* map_drawer1{ new MapDrawer{ map_drawer_go, "../configs/map1.json", false } };
    MapDrawer* map_drawer2{ new MapDrawer{ map_drawer_go, "../configs/map2.json", false } };
    GameObject* car{ new GameObject{scene} };
    Movement* mover{ new Movement{car} };
    CarConf car_conf{ 500, 30, 1, 1, 0.1 };
    Force* force{ new Force{car, mover} };
    GameObject* check_origin{ new GameObject{scene} };
    RoadCheck* check{ new RoadCheck{ check_origin, map_drawer1->coords, map_drawer2->coords} };
    CarMovement* car_mover{ new CarMovement{car,force, car_conf, check} };
    new Renderer{ car, "../assets/penguin.png" };
    car_mover->decelerate = false;
    GameObject* camera_go{ new GameObject{car} };
    camera = new Camera{ camera_go, 10 };
    GameObject* wheel{ new GameObject{car} };
    new Renderer{ wheel, "../assets/wheel.png" };
    Rotor* rotor{ new Rotor{ wheel } };
    wheel->transform->position = sf::Vector2f{ 700, -700 };
    new WheelCarInput{ car, rotor, car_mover };

    

}

#endif
