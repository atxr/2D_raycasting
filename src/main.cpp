#include <SFML/Graphics.hpp>
#include <time.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 400), "sfml-app");
    sf::RectangleShape lines[5];
    
    srand (time(NULL));
    for (int i=0; i<5; i++)
    {
        lines[i] = sf::RectangleShape(sf::Vector2f(200 + i*50, 1));
        lines[i].rotate(i*360/5);
        lines[i].setPosition(rand() % 800, rand() % 400);
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
            window.draw(lines[i]);
        }

        window.display();
    }

    return 0;
}

