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
    static const sf::Color playerColor = sf::Color::Cyan;

    static const sf::Vector2f timerBarSize = { 300.0f, 20.0f };
    static const sf::Vector2f timerBarPosition = { 250.0f, 10.0f };
    static const sf::Color timerBarColor = sf::Color::White;
    static const sf::Color lowTimeBarColor = sf::Color::Red;

    static const float lowTimeUmbral = 0.5f;
    static const float roundTime = 2.0f;
    static const int missDamage = 1;

    static const sf::Vector2f queueFrontPosition = { 300.0f, 300.0f };

    static sf::RectangleShape CreatePlayerShape()
    {
        sf::RectangleShape shape(playerSize);
        shape.setFillColor(playerColor);
        shape.setOrigin(playerSize / 2.0f);
        shape.setPosition(playerPosition);
        return shape;
    }

    static bool IsGameKey(sf::Keyboard::Key key)
    {
        return key == sf::Keyboard::Key::Z || key == sf::Keyboard::Key::X || key == sf::Keyboard::Key::C;
    }

    Game::Game() : timeLeft(roundTime), score(0), window(sf::VideoMode({ screenWidth, screenHeight }), windowTitle), player(playerMaxHP, playerAttackCooldown, CreatePlayerShape()), queue(queueFrontPosition)
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
                window.close();
            
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                sf::Keyboard::Key key = keyPressed->code;

                if (IsGameKey(key) && player.IsAlive() && player.CanAttack())
                {
                    player.Attack();

                    if (queue.Front().IsRequiredKey(key))
                        Hit();
                    else
                        Miss();
                }
                else if (!player.IsAlive())
                {
                    if (key == sf::Keyboard::Key::R)
                        Restart();

                    else if (key == sf::Keyboard::Key::Escape)
                        window.close();
                }
            }
        }
    }

    void Game::Update(float dt)
    {
        player.Update(dt);

        if (player.IsAlive())
        {
            timeLeft -= dt;

            if (timeLeft <= 0.0f)
                Miss();
        }
    }

    bool Game::LowTime() const
    {
        return timeLeft < lowTimeUmbral;
    }

    void Game::Hit()
    {
        queue.KillFront();
        score++;
        timeLeft = roundTime;
    }

    void Game::Miss()
    {
        player.TakeDamage(missDamage);
        queue.KillFront();
        timeLeft = roundTime;
    }

    void Game::Draw()
    {
        window.clear(sf::Color::Black);

        window.draw(player);
        window.draw(queue);

        // UI de prueba: fuente temporal de Windows
        static const sf::Font font("C:/Windows/Fonts/arial.ttf");

        std::string keyName = "C";
        sf::Color keyColor = sf::Color::Green;

        if (queue.Front().IsRequiredKey(sf::Keyboard::Key::Z))
        {
            keyName = "Z";
            keyColor = sf::Color::Red;
        }
        else if (queue.Front().IsRequiredKey(sf::Keyboard::Key::X))
        {
            keyName = "X";
            keyColor = sf::Color::Blue;
        }

        sf::Text keyText(font, keyName, 80);
        keyText.setFillColor(keyColor);
        keyText.setPosition({ 370.0f, 120.0f });
        window.draw(keyText);

        sf::Text scoreText(font, "Score: " + std::to_string(score), 30);
        scoreText.setPosition({ 20.0f, 20.0f });
        window.draw(scoreText);

        sf::Text hpText(font, "HP: " + std::to_string(player.GetHP()), 30);
        hpText.setPosition({ 20.0f, 60.0f });
        window.draw(hpText);

        sf::RectangleShape timerBar({ timerBarSize.x * (timeLeft / roundTime), timerBarSize.y });
        timerBar.setPosition(timerBarPosition);
        timerBar.setFillColor(LowTime()? lowTimeBarColor : timerBarColor);
        window.draw(timerBar);

        if (!player.IsAlive())
        {

            sf::Text gameOverText(font, "GAME OVER \nFINAL SCORE: " + std::to_string(score) + "\nPRESS R TO RESTART" + "\nESC TO EXIT", 70);
            gameOverText.setPosition({ 10.0f, 120.0f });
            gameOverText.setFillColor(sf::Color::White);
            window.draw(gameOverText);
        }

        window.display();
    }

    void Game::Restart()
    {
        queue.Reset();
        score = 0;
        timeLeft = roundTime;
        player.RevivePlayer();
    }
}