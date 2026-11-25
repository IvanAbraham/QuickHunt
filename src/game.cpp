#include "game.h"

#include <SFML/Graphics.hpp>

namespace quickhunt
{
    static const int screenWidth = 800;
    static const int screenHeight = 600;
    static const char* windowTitle = "QuickHunt";

    static const int playerMaxHP = 3;
    static const float playerAttackCooldown = 0.2f;
    static const sf::Vector2f playerSize = { 50.0f, 80.0f };
    static const sf::Vector2f playerPosition = { 100.0f, 300.0f };
    static const sf::Color playerColor = sf::Color::White;

    static const sf::Vector2f queueFrontPosition = { 300.0f, 300.0f };

    static sf::RectangleShape CreatePlayerShape()
    {
        sf::RectangleShape shape(playerSize);
        shape.setFillColor(playerColor);
        shape.setOrigin(playerSize / 2.0f);
        shape.setPosition(playerPosition);
        return shape;
    }

    Game::Game() : window(sf::VideoMode({ screenWidth, screenHeight }), windowTitle), player(playerMaxHP, playerAttackCooldown, CreatePlayerShape()), queue(queueFrontPosition)
    {
        window.setKeyRepeatEnabled(false);
    }

    void Game::Run()
    {
        while (window.isOpen())
        {
            float dt = clock.restart().asSeconds();

            HandleEvents();
            Update(dt);
            Draw();
        }
    }

    void Game::HandleEvents()
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
    }

    void Game::Update(float dt)
    {
        player.Update(dt);
    }

    void Game::Draw()
    {
        window.clear(sf::Color::Black);

        window.draw(player);
        window.draw(queue);

        window.display();
    }
}