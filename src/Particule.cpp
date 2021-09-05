#include "Particule.h"

Particule::Particule()
{
    *this = Particule(400,200);
}

Particule::Particule(int x, int y) : m_x(x), m_y(y) {}

sf::Vector2f Particule::getPos() { return sf::Vector2f(m_x, m_y); }

void Particule::update(sf::Vector2i mousePos)
{
    m_x = mousePos.x; 
    m_y = mousePos.y;
}

void Particule::draw(sf::RenderWindow *window)
{
    sf::CircleShape cirle = sf::CircleShape(4);
    cirle.setOrigin(2,2);
    cirle.setPosition(getPos());
    window->draw(cirle);
}
