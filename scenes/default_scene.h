#ifndef DEFAULT_SCENE_H
#define DEFAULT_SCENE_H

#include "game_object.h"
#include "components.h"
#include <vector>
#include <string>

GameObject* create_penguin(GameObject* scene, Camera* camera) {
    GameObject* go{ new GameObject{scene} };
    Renderer* rend{ new Renderer{go, "../assets/penguin.png", camera} };
    go->transform->position = sf::Vector2f{ 1000, 1000 };
    return go;
}

GameObject* create_map_drawer(GameObject* scene, std::string path,
    bool write, sf::PrimitiveType draw_mode) {
    GameObject* go{ new GameObject{scene} };
    new MapDrawer{ go, path, write, draw_mode };
    return go;
}

std::tuple<GameObject*, CarMovement*> create_car(GameObject* scene, Camera* camera, RoadCheck* check) {
    GameObject* car{ new GameObject{scene} };
    Movement* mover{ new Movement{car} };
    CarConf car_conf{ 500, 30, 1, 1, 0.1 };
    Force* force{ new Force{car, mover} };
    CarMovement* car_mover{ new CarMovement{car,force, car_conf, check} };
    new Renderer{ car, "../assets/penguin.png", camera };
    car_mover->decelerate = false;
    return { car, car_mover };
}

std::vector<GameObject*> create_cars(GameObject* scene, int cnt,
    Client* client, Camera* camera, RoadCheck* check) {
    std::vector<GameObject*> res{ cnt };
    res[client->this_ind] = client->go;
    for (int i = 0; i < cnt; i++) {
        if (i == client->this_ind) {
            continue;
        }
        res.push_back(std::get<0>(create_car(scene, camera, check)));
    }
    return res;
}

void create_defualt_scene(GameObject*& scene,
    Camera*& camera, Client*& client,
    std::string server_ip, std::string port,
    RoadCheck*& check) {
    scene = new GameObject{ nullptr };
    GameObject* map_drawer_go{ new GameObject{scene} };
    MapDrawer* map_drawer1{ new MapDrawer{
        map_drawer_go, "../configs/map1.json", false, sf::LinesStrip} };
    MapDrawer* map_drawer2{ new MapDrawer{
         map_drawer_go, "../configs/map2.json", false, sf::LinesStrip } };

    GameObject* check_origin{ new GameObject{scene} };
    check = new RoadCheck{ check_origin,
        map_drawer1->coords.points,
        map_drawer2->coords.points };

    GameObject* car;
    CarMovement* car_mover;
    std::tie(car, car_mover) = create_car(scene, camera, check);
    client = new Client{car, server_ip, port};
    GameObject* camera_go{ new GameObject{car} };
    camera = new Camera{ camera_go, 10 };
    GameObject* wheel{ new GameObject{car} };
    new Renderer{ wheel, "../assets/wheel.png", camera };
    Rotor* rotor{ new Rotor{ wheel } };
    wheel->transform->position = sf::Vector2f{ 700, -700 };
    new WheelCarInput{ car, rotor, car_mover };

    MapDrawer* map_drawer3{ new MapDrawer{
        map_drawer_go, "../configs/map3.json", true, sf::Lines
    } };

    GameObject* checkpoints_go{ new GameObject{scene} };
    LoopCounter* checkpoints{ new LoopCounter{checkpoints_go,
     map_drawer3->coords.points,
      car->transform, 50, true} };
}

#endif
