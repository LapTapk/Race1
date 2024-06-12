#include "game.h"
#include "game_object.h"
#include "components/client.h"
#include "default_scene.h"
#include "components/camera.h"
#include <iostream>
#include <string>
#include <sstream>

std::tuple<int, int> parse_reply(std::string reply) {
    std::stringstream ss{ reply };
    std::string str;
    getline(ss, str, ' ');
    int cnt{ stoi(str) };
    getline(ss, str, ' ');
    int ind{ stoi(str) };
    return { cnt, ind };
}

int main() {
    std::string server_ip, port;
    std::cout << "Insert server ip: " << std::flush;
    std::cin >> server_ip;
    std::cout << "Insert server port: " << std::flush;
    std::cin >> port;

    GameObject* scene;
    Camera* camera;
    Client* client;
    RoadCheck* check;
    create_defualt_scene(scene, camera, client, server_ip, port, check);

    char _;
    std::cout << "Type 1 when ready";
    std::cin >> _;
    std::cout << "hui";

    client->send_message("ready");
    while (client->reply == "") {}
    int cnt, ind;
    std::tie(cnt, ind) = parse_reply(client->reply);
    client->this_ind = ind;
    client->players = create_cars(scene, cnt, client, camera, check);

    GameConf conf("../configs/conf.json");
    Game game(conf, scene, camera, server_ip, port);
    game.run();
}