#include <doctest.h>
#include "components/force.h"
#include "components/transform.h"
#include "components/movement.h"

TEST_CASE("Apllying force") {
    GameObject* go{ new GameObject{nullptr} };
    Movement* mover{ new Movement{go} };
    Force* force{ new Force{go, mover} };
    force->accelerations.push_back({ 5, 0.7 });
    force->accelerations.push_back({ -1, 100 });
    force->accelerations.push_back({ 7, -5.2 });

    
    go->update();
    CHECK_EQ(mover->vector, sf::Vector2f{ 11, 95.5 } * 0.5f);
    go->update();
    CHECK_EQ(mover->vector, sf::Vector2f{ 22, 191 } * 0.5f);
}