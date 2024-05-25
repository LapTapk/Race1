#include "components/camera.h"

Camera::Camera(GameObject* go, float zoomout_c) :
    Component(go), zoomout(zoomout_c) {}