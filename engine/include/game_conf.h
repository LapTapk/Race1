#ifndef GAME_CONF_H
#define GAME_CONF_H

#include <string>

class GameConf {
public:
    GameConf(std::string conf_path);
    int default_camera_offset;
    std::pair<int, int> window_size;
    std::string title;
};

#endif