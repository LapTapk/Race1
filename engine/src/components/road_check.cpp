#include "components/road_check.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "components/transform.h"
#include "components/car/car_movement.h"
#include <cmath>
#include "utils.h"

RoadCheck::RoadCheck(GameObject* go,
    MapCoords& outborders_c, MapCoords& inborders_c) :
    Component{ go }, outborders{ outborders_c },
    inborders{ inborders_c } {}

void add_lines(std::vector<line>& lines, MapCoords& borders) {
    std::vector<sf::Vector2f>& points{ borders.points };
    for (int i = 0; i < points.size() - 1; i++) {
        line l{ points[i], points[i + 1] };
        lines.push_back(l);
    }
}

bool RoadCheck::is_on_road(CarMovement* mover) {
    std::vector<line> lines;
    add_lines(lines, outborders);
    add_lines(lines, inborders);

    line check_line{
        go->transform->global_pos(),
        mover->go->transform->global_pos(),
    };

    int cnt{ 0 };
    for (line& l : lines) {
        if (check_line.are_intersecting(l)) {
            cnt++;
        }
    }

    return cnt % 2 != 0;
}