#include "components/force.h"
#include <numeric>
#include <cmath>

Force::Force(GameObject* go, Mover* mover_c) :
    Component(go), mover(mover_c) {}

void Force::update() {
    sf::Vector2f acc_sum{
        std::accumulate(accelerations.begin(), accelerations.end(), sf::Vector2f{})
    };

    sf::Vector2f double_delta_vector{
        acc_sum.x * acc_sum.x, acc_sum.y * acc_sum.y };
    mover->vector += double_delta_vector / 2.0f;
}