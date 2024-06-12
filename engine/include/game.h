#ifndef GAME_H
#define GAME_H

#include "event_manager.h"
#include "game_object.h"
#include "game_conf.h"
#include "components/camera.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

/**
 * Основной класс игры. Отвечает за глобальные состояния и
 * покадровый подсчет.
*/
class Game {
public:
    static Game* instance; ///< Синглтон
    std::unique_ptr<GameObject> scene;///< Указатель на текущую сену
    Camera* camera;///< Указатель на основную камеру сцены
    sf::RenderWindow window;///< Окно, в котором происходит отрисовка игры
    EventManager event_manager;///< Обработчик событий ввода/вывода 
    GameConf conf;///< Начальные конфигурации игры
    bool running = false;///< Состояние, указывающее на то, запущена ли игрa
    std::string server_ip;
    std::string port;
    /**
     * Основная функция класса. Запускает покадровый подсчет.
    */
    void run();
    /**
     * Геттер поля delta_time
     *
     * @returns delta_time
    */
    float get_delta_time();
    /**
     * Инициализатор класса
     *
     * @param conf Начальные конфигурации игры
     * @param scene Начальная сцена игры
     * @param camera Камера, принадлежащая scene
    */
    Game(GameConf conf, GameObject* scene, Camera* camera,
        std::string server_ip, std::string port);
    /**
     * Деструктор Game. Запускает деструктор сцены
    */
    ~Game();
private:
    sf::Clock clock;///< Часы, чтобы отмерять fps
    float delta_time;///< Время прощедшее с предыдущего кадра
    void iteration();///< Вспомогательная функция подсчета одного кадра
};

#endif 