#include <SFML/Graphics.hpp>
#include <time.h>
#include "Wall.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 400), "sfml-app");
    Wall walls[5];
    
    srand (time(NULL));
    for (int i=0; i<5; i++)
    {
        walls[i] = Wall();
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i=0; i<5; i++)
        {
            sf::Vertex line[2] = {sf::Vertex(walls[i].get1()), sf::Vertex(walls[i].get2())};
            window.draw(line, 2, sf::Lines);
        }

        window.display();
    }

    return 0;
}

