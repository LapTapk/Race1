#include "game.h"
#include "game_object.h"
#include "components/client.h"
#include "default_scene.h"
#include "components/camera.h"
#include <iostream>
#include <server_io.h>
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

    ServerIO sio{ server_ip, port };
    
    char _;
    std::cout << "Type any letter when ready ";
    std::cin >> _;

    sio.send_message("ready");
    while (sio.reply == "") {}

    int cnt, ind;
    std::tie(cnt, ind) = parse_reply(sio.reply);
    ind--;

    GameObject* scene;
    Camera* camera;
    create_defualt_scene(scene, camera, sio, cnt, ind);
    GameConf conf("../configs/conf.json");
    
    Game game(conf, scene, camera, server_ip, port);
    game.run();
}