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

// A very basic entity for testing purposes
class TestEntity : public Entity
{
public:
    TestEntity();
    void update(GameManager *manager) override;
    void draw(RenderWindow *window) override;
};

// Constructor with some default values
TestEntity::TestEntity()
{
    health = 1;
    max_speed = 2.5f;
    move_speed = 0.1f;
}

// No need to implement, but defined to prevent from being absrtact
void TestEntity::update(GameManager *manager) {}

// Draw the body to the screen
void TestEntity::draw(RenderWindow *window)
{
    window->draw(body);
}

int main()
{
    cout << "\n========== Program Start ==========\n"
         << endl;

    // Create the window
    RenderWindow window(sf::VideoMode(1280, 720),
                        "Hitbox2 Test");

    // Reducing the framerate to 60fps
    window.setFramerateLimit(60);

    // Using the game manager
    GameManager manager(&window);

    // Entities to play with
    TestEntity *unmoving = new TestEntity;
    unmoving->body.setPosition(300.f, 300.f);
    unmoving->body.setSize(Vector2f(100.f, 100.f));
    manager.addEnemy(unmoving);

    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            TestEntity *temp = new TestEntity;
            temp->body.setSize(Vector2f(20.f, 20.f));

            temp->body.setPosition(220.f + x * 60.f,
                                   80.f + 520.f * y);

            if (y)
                temp->body.setFillColor(Color::Red);
            else
                temp->body.setFillColor(Color::Magenta);

            temp->changeVelocity(0.f, 1.f - 2.f * y);

            manager.addEnemy(temp);
        }
    }

    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 2; x++)
        {
            TestEntity *temp = new TestEntity;
            temp->body.setSize(Vector2f(20.f, 20.f));

            temp->body.setPosition(80.f + 520.f * x,
                                   220.f + y * 60.f);

            if (x)
                temp->body.setFillColor(Color::Yellow);
            else
                temp->body.setFillColor(Color::Cyan);

            temp->changeVelocity(1.f - 2.f * x, 0.f);

            manager.addEnemy(temp);
        }
    }

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

        // Moving
        manager.updateEnemies();

        // Drawing entities
        window.clear();

        manager.drawEnemies();

        window.display();
    }

    cout << "\n=============== End ===============\n"
         << endl;

    return 0;
}