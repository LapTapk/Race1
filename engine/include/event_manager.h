#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H 

#include <SFML/Graphics.hpp>

/**
 * Класс, отвечающий за хранение 
 * событий ввода/вывода. Каждый кадр
 * обновляется ввод/вывод для данного кадра.
*/
class EventManager {
public:
    std::vector<sf::Event> events;///< События ввода/вывода для текущего кадра
    void update();///< Функция обработки кадра
};

#endif