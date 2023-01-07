#include <iostream>
using std::cout;
using std::endl;

#include <cmath>
using std::sqrt;

#include <SFML/Graphics.hpp>
using sf::CircleShape;
using sf::Color;
using sf::RectangleShape;
using sf::RenderWindow;

#include <SFML/System.hpp>
using sf::Vector2f;

#include "GameLibrary/GameLibrary.h"

// A very basic player for testing purposes
class TestPlayer : public Entity
{
public:
    TestPlayer();
    void update(GameManager *manager) override;
    void draw(RenderWindow *window) override;
};

// Constructor with some default values
TestPlayer::TestPlayer()
{
    body.setFillColor(Color::Cyan);
    body.setSize(Vector2f(25.f, 25.f));
    body.setPosition(640.f, 360.f);
}

// No need to implement, but defined to prevent from being absrtact
void TestPlayer::update(GameManager *manager) {}

// Draw the body to the screen
void TestPlayer::draw(RenderWindow *window)
{
    window->draw(body);
}

// A test enemy
class TestEnemy : public Entity
{
public:
    TestEnemy();
    void update(GameManager *manager) override;
    void draw(RenderWindow *window) override;
};

// Construct with some default values
TestEnemy::TestEnemy()
{
    body.setFillColor(Color::Magenta);
    body.setSize(Vector2f(25.f, 25.f));
    body.setPosition(500.f, 500.f);
    health = 1;
    max_speed = 1.f;
    move_speed = 0.1f;
}

// Move in the direction of the player
void TestEnemy::update(GameManager *manager)
{
    // Chase logic
    Vector2f vec = manager->player->getCenter() - getCenter();
    const float vec_mag = sqrt(vec.x * vec.x + vec.y * vec.y);
    vec /= vec_mag;
    vec *= move_speed;
    changeVelocity(vec);
}

// Draw the body to the screen
void TestEnemy::draw(RenderWindow *window)
{
    window->draw(body);
}

int main()
{
    cout << "\n========== Program Start ==========\n"
         << endl;

    // Create the window
    RenderWindow window(sf::VideoMode(1280, 720),
                        "Entity1 Test");

    // Reducing the framerate to 60fps
    window.setFramerateLimit(60);

    // Gamelibrary stuff

    // Create an entity for the player
    TestPlayer player;

    // Create some enemies to play with the player
    TestEnemy enemy = TestEnemy();
    enemy.changeVelocity(2.f, 0.f);

    // Create the manager and pass the necessary stuff to it
    GameManager manager(&window);
    manager.setPlayer(&player);
    manager.addEnemy(&enemy);

    // Where the event being handled is stored
    sf::Event event;

    // Game loop
    while (window.isOpen())
    {
        // Event handler
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed: // Window closed
                window.close();
                break;

            case sf::Event::KeyPressed: // Escape key pressed
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            default:
                break;
            }
        }

        // Updates here
        manager.updateEnemies();

        // Drawing entities
        window.clear();

        manager.drawPlayer();
        manager.drawEnemies();

        window.display();
    }

    cout << "\n=============== End ===============\n"
         << endl;

    return 0;
}