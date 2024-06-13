#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <boost/asio.hpp>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <SFML/Graphics.hpp>
#include <thread>
#include "game_object.h"
#include "components/transform.h"
#include "server_io.h"

using boost::asio::ip::tcp;

class Client : public Component {
public:
    ServerIO& sio;
    std::vector<sf::Vector2f> coords;
    std::vector<GameObject*> players;
    int this_ind;
    std::string create_mes();
    void parse_coords(
        std::string mes);
    Client(GameObject* go, ServerIO& sio,
        int this_ind, std::vector<GameObject*> players);
    void set_positions();
    void update() override;
};

#endif