#include "game.h"
#include <iostream>

const sf::Time TimePerFrame = sf::seconds(1.f/60.f);
const float PlayerSpeed=100.f;

Game::Game():mWindow(sf::VideoMode(800,600), "SFML"),
             mPlayer()
             , mStatisticsText()
             , mStatisticsUpdateTime()
             , mStatisticsNumFrames(0)
             , mIsMovingUp(false)
             , mIsMovingDown(false)
             , mIsMovingRight(false)
             , mIsMovingLeft(false)
{
    //mPlayer.setRadius(40.f);
    //mPlayer.setPosition(100.f,100.f);
    //mPlayer.setFillColor(sf::Color::Cyan);


    // Load a sprite to display
    //if (!mTexture.loadFromFile("Media/Textures/Eagle.png"))
    //{
        // Fail load texture
    //}

    try {
        textures.load(Textures::Eagle,"Media/Textures/Eagle.png");
        //mFont.loadFromFile("Media/arial.ttf");
        fonts.load(Fonts::Arial,"Media/arial.ttf");
    }

    catch (std::runtime_error& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		//return 1;
	}

    mPlayer.setTexture(textures.get(Textures::Eagle));
    mPlayer.setPosition(100.f,100.f);


	mStatisticsText.setFont(fonts.get(Fonts::Arial));
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);
}
void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
	// Start the game loop
    while (mWindow.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        updateStatistics(elapsedTime);
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
        mWindow.draw(mStatisticsText);

        // Update the window
        mWindow.display();

}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{

		mStatisticsText.setString(L"Кадров в секунду = " + towString(mStatisticsNumFrames) + L"\n" +
			L"Время обновления = " + towString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + L"us");
        mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

