#include "doctest.h"
#include "components/map_drawer.h"
#include <string>
#include <algorithm>

TEST_CASE("Adding points") {
    MapCoords coords{ "" };
    coords.points.push_back({ 1, 2 });
    coords.points.push_back({ 4, 3 });
    coords.points.push_back({ 5, 6 });

    std::string right{
        "{\"points\":[[1,2],[4,3],[5,6]]}" };
    std::string actual{
        coords.to_json().toStyledString()
    };

    auto p{ [](char& x) {return isspace(x);} };
    auto result{ std::remove_if(actual.begin(), actual.end(), p) };
    actual.erase(result, actual.end());

    CHECK(right == actual);
}