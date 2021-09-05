#ifndef PARTICULE_H
#define PARTICULE_H

#include "Ray.h"
#include <SFML/Graphics.hpp>

class Particule {
    public:
    Particule();
    Particule(int x, int y);

    void update(sf::Vector2i mousePos);
    sf::Vector2f getPos();
    void draw(sf::RenderWindow *window);

    private:
    int m_x, m_y;
    Ray m_rays[10];
};

#endif
