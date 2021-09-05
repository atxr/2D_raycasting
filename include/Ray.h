#ifndef RAY_H
#define RAY_H

#include <SFML/Graphics.hpp>

class Ray {
    public:
        Ray();
        Ray(int theta);
        void draw(sf::Vector2f origin, sf::RenderWindow *window);

    private:
        int m_theta;
};

#endif
