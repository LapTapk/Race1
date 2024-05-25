#include "game.h"
#include "default_scene.h"
#include "components/camera.h"

int main() {
    GameObject* scene;
    Camera * camera;
    create_defualt_scene(scene, camera);
    GameConf conf("../configs/conf.json");
    Game game(conf, scene, camera);
    game.run();
}