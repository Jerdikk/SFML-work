#include "game.h"

const sf::Time TimePerFrame = sf::seconds(1.f/60.f);
const float PlayerSpeed=100.f;

Game::Game():mWindow(sf::VideoMode(800,600), "SFML"), mPlayer()
{
    mPlayer.setRadius(40.f);
    mPlayer.setPosition(100.f,100.f);
    mPlayer.setFillColor(sf::Color::Cyan);

    // Load a sprite to display
   // sf::Texture texture;
   // if (!texture.loadFromFile("cb.bmp"))
   //     return EXIT_FAILURE;
   // sf::Sprite sprite(texture);


}
void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
	// Start the game loop
    while (mWindow.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
if (key==sf::Keyboard::W)
    mIsMovingUp = isPressed;
if (key==sf::Keyboard::S)
    mIsMovingDown = isPressed;
if (key==sf::Keyboard::A)
    mIsMovingLeft = isPressed;
if (key==sf::Keyboard::D)
    mIsMovingRight = isPressed;

}

void Game::processEvents()
{
        // Process events
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code,true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code,false);
                break;
            case sf::Event::Closed:
                // Close window : exit
                mWindow.close();
                break;
            }

        }


}

void Game::update(sf::Time deltaTime)
{

    sf::Vector2f movement(0.f,0.f);
    if (mIsMovingUp)
        movement.y -= PlayerSpeed;
    if (mIsMovingDown)
        movement.y += PlayerSpeed;
    if (mIsMovingLeft)
        movement.x -= PlayerSpeed;
    if (mIsMovingRight)
        movement.x += PlayerSpeed;

    mPlayer.move(movement*deltaTime.asSeconds());
}

void Game::render()
{
        // Clear screen
        mWindow.clear();

        // Draw the sprite
       // mWindow.draw(sprite);
        mWindow.draw(mPlayer);

        // Update the window
        mWindow.display();

}
