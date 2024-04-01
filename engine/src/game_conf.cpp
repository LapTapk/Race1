#include "game_conf.h"
#include <jsoncpp/json/json.h>
#include <fstream>

GameConf::GameConf(std::string path) {
    std::ifstream conf_cin(path);
    Json::Value conf;
    conf_cin >> conf;

    default_camera_offset = conf["default_camera_offset"].asInt();
    window_size = std::make_pair(conf["window_size"][0u].asInt()
        , conf["window_size"][1u].asInt());
    title = conf["title"].asString();
}