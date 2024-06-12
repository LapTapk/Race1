#ifndef CAMERA_H
#define CAMERA_H

#include "game_object.h"

/**
 * Компонент камеры
 */
class Camera : public Component {
public:
    /**
     * Конструктор Camera
     * 
     * @param go Родительский объект
     * @param zoomout Коэффициент отдаления камеры от сцены
     */
    Camera(GameObject* go, float zoomout = 1);
    float zoomout;///< Коэффициент отдаления камеры от сцены 
};

#endif