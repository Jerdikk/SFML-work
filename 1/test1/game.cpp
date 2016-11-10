#include "game.h"

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
	// Start the game loop
    while (mWindow.isOpen())
    {
        processEvents();
        update();
        render();
    }
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

void Game::update()
{
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
