#include <SFML/Graphics.hpp>

class Wall
{
    public:
    //Constructors
    Wall();
    Wall(int x1, int y1, int x2, int y2);

    sf::Vector2f get1(); 
    sf::Vector2f get2(); 

    private:
    int m_x1, m_y1;
    int m_x2, m_y2;
};

