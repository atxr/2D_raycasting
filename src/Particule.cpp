#include "Particule.h"

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

void Particule::draw(sf::RenderWindow *p_window)
{
    sf::CircleShape circle = sf::CircleShape(8);
    circle.setFillColor(sf::Color::Red);
    circle.setOrigin(4, 4);
    circle.setPosition(getPos());
    p_window->draw(circle);

    for (int i=0; i<10; i++)
    {
        m_rays[i].draw(getPos() + sf::Vector2f(4,4), p_window);
    }
}
