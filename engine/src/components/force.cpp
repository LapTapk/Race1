#include "components/force.h"
#include <numeric>
#include <cmath>

Force::Force(GameObject* go, Movement* mover_c) :
    Component(go), mover(mover_c) {}

void Force::update() {
    sf::Vector2f acc_sum{
        std::accumulate(accelerations.begin(),
        accelerations.end(),
        sf::Vector2f{0, 0})
    };

    mover->vector += acc_sum;
}