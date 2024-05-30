#include <SFML/Graphics.hpp>

struct line {
    sf::Vector2f a, b;
    line(sf::Vector2f a_c, sf::Vector2f b_c);
    bool ccw(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c);
    bool are_intersecting(line& other);
};

void draw_lines(std::vector<sf::Vector2f>& coords);
sf::Vector2f get_mpos();
bool called_left_click();
