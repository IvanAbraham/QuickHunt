#include "game.h"

#include <SFML/Graphics.hpp>

namespace quickhunt
{
    void Run()
    {
        sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "QuickHunt");

        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }
            }

            window.clear(sf::Color::Black);
            window.display();
        }
    }
}