#include "Particule.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Wall.h"
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 400), "sfml-app");
    srand (time(NULL));
    
    Wall walls[5];
    for (int i=0; i<5; i++)
    {
        walls[i] = Wall();
    }

    Particule particule;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        //draw walls 
        for (int i=0; i<5; i++)
        {
            sf::Vertex line[2] = {sf::Vertex(walls[i].get1()), sf::Vertex(walls[i].get2())};
            window.draw(line, 2, sf::Lines);
        }

        // if mouse is pressed, move particule
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            particule.update(sf::Mouse::getPosition(window));
        }
        particule.draw(&window);

        window.display();
    }

    return 0;
}

