#ifndef TEST_CMP_H
#define TEST_CMP_H

#include "component.h"

class TestCmp : public Component {
public:
    TestCmp(GameObject* go);
    void update() override;
};

#endif