#include "Ray.h"
#include <math.h>

Ray::Ray() : m_theta(0) {}
Ray::Ray(int theta) : m_theta(theta) {}

void Ray::draw(sf::Vector2f origin, sf::RenderWindow *p_window)
{
    sf::RectangleShape line = sf::RectangleShape(sf::Vector2f(20,1));
    line.setPosition(origin);
    line.setFillColor(sf::Color::Yellow);
    line.rotate(m_theta);
    p_window->draw(line);
}
