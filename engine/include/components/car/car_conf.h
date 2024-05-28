#ifndef CAR_CONF_H
#define CAR_CONF_H

struct CarConf {
    float max_speed, acceleration,
        friction, rotation_delta, decelerate_coef;
};

#endif