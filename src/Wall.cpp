#include "Wall.h"

Wall::Wall()
{
    *this = Wall(rand() % 800, rand() % 400, rand() % 800, rand() % 400);
}

Wall::Wall(int x1, int y1, int x2, int y2) : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2) {}

sf::Vector2f Wall::get1() {return sf::Vector2f(m_x1, m_y1); }
sf::Vector2f Wall::get2() {return sf::Vector2f(m_x2, m_y2); }

