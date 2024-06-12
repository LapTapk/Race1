#ifndef ROTOR_H
#define ROTOR_H

#include "game_object.h"

/**
 * Компонент, отвечащий за
 * вращение обеъекта в зависимости 
 * от позиции мыши
 */
class Rotor : public Component {
public:
    /**
     * Конструктор Rotor
     * 
     * @param go Родительский объект
     */
    Rotor(GameObject* go);
    /**
     * @returns Ориентация в зависимости от позиции мыши
     */
    float get_rotation();
    /**
     * Функция обработки кадра
     */
    void update() override;
};

#endif