#include "game.h"
#include "default_scene.h"

int main() {
    GameObject* scene, * camera;
    create_defualt_scene(scene, camera);
    GameConf conf("../conf.json");
    Game game(conf, scene, camera);
    game.run();
}