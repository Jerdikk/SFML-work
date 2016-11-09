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
            }
            // Close window : exit
            if (event.type == sf::Event::Closed)
                mWindow.close();
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
