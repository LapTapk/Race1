#ifndef GAME_CONF_H
#define GAME_CONF_H

#include <string>

class GameConf {
public:
    GameConf(std::string conf_path);
    std::pair<int, int> window_size;
    std::string title;
    int fps;
    int wheel_rot_delta;
};

#endif