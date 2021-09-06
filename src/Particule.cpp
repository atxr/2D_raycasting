#include "Particule.h"
#include <math.h>

float size(sf::Vector2f v)
{
    return sqrt(pow(v.x, 2) + pow(v.y, 2));
}

Particule::Particule() : Particule(400,200) {}
Particule::Particule(int x, int y) : m_x(x), m_y(y) 
{
    for (int i=0; i<10; i++)
    {
        m_rays[i] = Ray(36*i);
    }
}

sf::Vector2f Particule::getPos() { return sf::Vector2f(m_x, m_y); }

void Particule::update(sf::Vector2i mousePos)
{
    m_x = mousePos.x; 
    m_y = mousePos.y;
}

void Particule::draw(Wall walls[5], sf::RenderWindow *p_window)
{
    sf::CircleShape circle = sf::CircleShape(8);
    circle.setFillColor(sf::Color::Red);
    circle.setOrigin(4, 4);
    circle.setPosition(getPos());
    p_window->draw(circle);

    sf::Vector2f origin = getPos() + sf::Vector2f(4,4);

    for (int i=0; i<10; i++)
    {   
        float length(-1);
        for (int j=0; j<5; j++)
        {
            sf::Vector2f collision = m_rays[i].check(origin, &walls[j]);
            if (collision != sf::Vector2f(0,0))
            {
                // update length of the ray
                if (length < 0 || length > size(collision-origin))
                {
                    length = size(collision - origin);
                }
            }
        }

        m_rays[i].draw(origin, length, p_window);
    }
}
