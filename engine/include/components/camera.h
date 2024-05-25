#ifndef CAMERA_H
#define CAMERA_H

#include "game_object.h"

class Camera : public Component {
public:
    Camera(GameObject* go, float zoomout = 1);
    float zoomout;    
};

#endif