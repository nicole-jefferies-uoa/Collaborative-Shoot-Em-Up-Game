#include "GameLoop.h"

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

#include "GameLibrary/GameLibrary.h"

/*
 *
 */
GameLoop::GameLoop()
{
    frame_counter = -1;

    difficulty = 0;

    difficulty_increase = 420;

    basic_enemy_spawn_delay = 120;
    basic_enemy_max_spawn_threshold = 40;

    fast_enemy_spawn_delay = 150;
    fast_enemy_max_spawn_threshold = 30;

    big_enemy_spawn_delay = 300;
    big_enemy_max_spawn_threshold = 60;

    lose_frame = -1;
}

/*
 *  Runs the game loop, will run until the game exits
 */
void GameLoop::runGameLoop()
{
    // Create the window
    RenderWindow window(sf::VideoMode(1280, 720),
                        "OOP Group Project",
                        sf::Style::Titlebar | sf::Style::Close);

    // Reducing the framerate to 60fps
    window.setFramerateLimit(60);

    // Loading and creating textures
    Texture player_texture;
    player_texture.loadFromFile("images/Not-Mooncake.png");
    Texture basic_enemy_texture;
    basic_enemy_texture.loadFromFile("images/Chonk-Child.png");
    Texture fast_enemy_texture;
    fast_enemy_texture.loadFromFile("images/Smol-Child.png");
    Texture big_enemy_texture;
    big_enemy_texture.loadFromFile("images/Mega-Chonk.png");

    // Where the event being handled is stored
    sf::Event event = sf::Event();

    // Game manager yay
    GameManager manager = GameManager(&window);

    // The player
    Player player;
    player.body.setTexture(&player_texture);
    manager.setPlayer(&player);

    // Game loop
    while (window.isOpen())
    {
        // Event handler
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed: // Window closed
                    lose_frame = frame_counter;
                    window.close();
                    break;

                case sf::Event::KeyPressed: // Escape key pressed
                    if (event.key.code == sf::Keyboard::Escape)
                        lose_frame = frame_counter;
                    window.close();
                    break;

                default:
                    break;
            }
        }

        // Frame counting
        frame_counter++;

        // Increasing difficulty
        if (frame_counter % difficulty_increase == 0)
        {
            difficulty++;

            if (basic_enemy_spawn_delay > basic_enemy_max_spawn_threshold)
                basic_enemy_spawn_delay--;

            if (fast_enemy_spawn_delay > fast_enemy_max_spawn_threshold)
                fast_enemy_spawn_delay--;

            if (big_enemy_spawn_delay > big_enemy_max_spawn_threshold)
                big_enemy_spawn_delay--;
        }

        // Spawning basic enemy
        if (frame_counter % basic_enemy_spawn_delay == 0)
        {
            auto *temp = new BasicEnemy();
            temp->body.setTexture(&basic_enemy_texture, true);
            manager.addEnemy(temp);
        }

        // Spawning fast enemy
        if (frame_counter % fast_enemy_spawn_delay == 0)
        {
            auto *temp = new FastEnemy();
            temp->body.setTexture(&fast_enemy_texture);
            manager.addEnemy(temp);
        }

        // Spawning big enemy
        if (frame_counter % big_enemy_spawn_delay == 0)
        {
            auto *temp = new BigEnemy();
            temp->body.setTexture(&big_enemy_texture);
            manager.addEnemy(temp);
        }

        // Bullet spawning
        Vector2i mouse_pos = sf::Mouse::getPosition(window);
        player.fire(&manager, mouse_pos);

        // Updates
        manager.updateAll();

        // Lose condition
        if (manager.checkLoseCondition() && lose_frame == -1)
            lose_frame = frame_counter;

        // Drawing stuff
        window.clear(Color(37, 37, 37));

        manager.drawAll();

        // Deleting necessary stuff
        manager.deleteAllNecessary();

        // WOO
        window.display();

        // If the game is lost
        if (manager.loss)
        {
            // After 60 frames from lose frame, exit loop
            if (frame_counter > lose_frame + 60)
                break;
        }
    }
}

/*
 * Resets all the necessary values
 */
void GameLoop::reset()
{
    frame_counter = -1;

    difficulty = 0;

    difficulty_increase = 420;

    basic_enemy_spawn_delay = 120;
    basic_enemy_max_spawn_threshold = 40;

    fast_enemy_spawn_delay = 150;
    fast_enemy_max_spawn_threshold = 30;

    big_enemy_spawn_delay = 300;
    big_enemy_max_spawn_threshold = 60;

    lose_frame = -1;
}
