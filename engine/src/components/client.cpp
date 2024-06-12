#include "components/client.h"
#include <iostream>
#include <boost/asio.hpp>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <SFML/Graphics.hpp>
#include <thread>
#include "game_object.h"
#include "components/transform.h"

using boost::asio::ip::tcp;

std::string Client::create_mes() {
    std::string res{ "" };
    sf::Vector2f pos{
        go->transform->position
    };

    std::string x{ std::to_string(pos.x) };
    std::string y{ std::to_string(pos.y) };
    res += x + " " + y;

    return res;
}


void Client::parse_coords(
    std::string mes) {
    std::string str;
    std::stringstream ss(mes);
    getline(ss, str, ' ');
    int ind{ stoi(str) };
    getline(ss, str, ' ');
    float x{ stof(str) };
    getline(ss, str, ' ');
    float y{ stof(str) };

    coords[ind] = { x, y };
}

void Client::read_from_server(tcp::socket& socket) {
    try {
        char data[1024];
        for (;;) {
            boost::system::error_code error;
            std::size_t length = socket.read_some(boost::asio::buffer(data), error);
            if (error == boost::asio::error::eof) {
                break; // Соединение закрыто сервером
            }
            else if (error) {
                throw boost::system::system_error(error); // Другие ошибки
            }

            reply = std::string{ data };
        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception in read thread: " << e.what() << "\n";
    }
}

Client::Client(GameObject* go, std::string server_ip_c,
    std::string port_c) :
    server_ip{ server_ip_c }, port{ port_c },
    Component{ go },
    socket{ io_context },
    io_context{}
{
    tcp::resolver resolver(io_context);
    auto endpoints = resolver.resolve(server_ip, port);
    boost::asio::connect(socket, endpoints);
    reader_thread = new std::thread(
        &Client::read_from_server, this, std::ref(socket)
    );
}

void Client::send_message(std::string mes) {
    try {
        std::string message{ mes };
        boost::asio::write(socket, boost::asio::buffer(message));
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}

void Client::set_positions() {
    parse_coords(reply);
    for (int i = 0; i < players.size(); i++) {
        if (i == this_ind) {
            continue;
        }

        players[i]->transform->position = coords[i];
    }
}

void Client::update() {
    send_message(create_mes());
    set_positions();
}

Client::~Client() {
    socket.close();
    reader_thread->join();
}