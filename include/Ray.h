#ifndef RAY_H
#define RAY_H

#include <SFML/Graphics.hpp>
#include "Wall.h"

class Ray {
    public:
        Ray();
        Ray(int theta);
        sf::Vector2f check(sf::Vector2f origin, Wall *wall);
        void draw(sf::Vector2f origin, sf::Vector2f collision, sf::RenderWindow *window);

    private:
        int m_theta;
};

#endif
