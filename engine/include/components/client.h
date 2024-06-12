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

using boost::asio::ip::tcp;

class Client : public Component {
public:
    std::string server_ip;
    std::string port;
    boost::asio::io_context io_context;
    tcp::socket socket;
    std::vector<sf::Vector2f> coords;
    std::vector<GameObject*> players;
    std::thread* reader_thread;
    std::string reply{ "" };
    int this_ind;
    std::string create_mes();
    void parse_coords(
        std::string mes);
    void read_from_server(tcp::socket& socket);
    Client(GameObject* go, std::string server_ip,
        std::string port);
    void send_message(std::string mes);
    void set_positions();
    void update() override;
    ~Client();
};

#endif