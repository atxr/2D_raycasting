#include "Ray.h"
#include <math.h>

float size(sf::Vector2f v)
{
    return sqrt(pow(v.x, 2) + pow(v.y, 2));
}

Ray::Ray() : m_theta(0) {}
Ray::Ray(int theta) : m_theta(theta) {}

sf::Vector2f Ray::check(sf::Vector2f origin, Wall *p_wall)
{
    float x1 = origin.x;
    float y1 = origin.y;
    float x2 = x1 + 100*cos(m_theta);
    float y2 = y1 + 100*sin(m_theta);

    float x3 = p_wall->get1().x;
    float y3 = p_wall->get1().y;
    float x4 = p_wall->get2().x;
    float y4 = p_wall->get2().y;

    float den = (x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4);
    if (den == 0)
    {
        return sf::Vector2f(0,0);
    }

    float t = ((x1 - x3)*(y3 - y4) - (y1 - y3)*(x3 - x4))/den;
    float u = ((x2 - x1)*(y1 - y3) - (y2 - y1)*(x2 - x3))/den;
    if (t>0 && u>0 && u<1)
    {
        return sf::Vector2f(x1 + t*(x2-x1), y1 + t*(y2-y1));
    }

    return sf::Vector2f(0,0);
}

void Ray::draw(sf::Vector2f origin, sf::Vector2f collision, sf::RenderWindow *p_window)
{
    sf::RectangleShape line = sf::RectangleShape(sf::Vector2f(size(collision - origin), 1));
    line.setPosition(origin);
    line.setFillColor(sf::Color::Yellow);
    line.rotate(m_theta);
    p_window->draw(line);
}
