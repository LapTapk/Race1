#ifndef FORCE_H
#define FORCE_H

#include "game_object.h"
#include "movement.h"
#include <SFML/Graphics.hpp>
#include <vector>

/**
 * Компонент, прилагающий силу к объекту по формуле.
 * Масса объекта не учитывается, только данное ускорение.
 */
class Force : public Component {
public:
    Movement* mover;///< Mover объекта
    std::vector<sf::Vector2f> accelerations;///< Список ускорений
    /**
     * Конструктор Force
     * 
     * @param go Родительский объект
     * @param mover Mover объекта
     */
    Force(GameObject* go, Movement* mover);
    /**
     * Функция счета кадра
     */
    void update() override;
};

#endif