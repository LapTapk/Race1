/*#include <doctest.h>
#include "game.h"
#include "components/renderer.h"
#include "components/transform.h"
#include "components/camera.h"

TEST_CASE("Position") {
    GameMock game;
    GameObject* scene{ game.scene.get() };
    Camera* cam{ game.camera };
    GameObject* go{ new GameObject{scene} };
    Renderer* rend{ new Renderer{go, "../assets/penguin.png", cam} };
    go->transform->position = {-5, 7};

    sf::Vector2f actual{rend->position()};
    sf::Vector2f right;
    CHECK_EQ(right, actual);
}*/