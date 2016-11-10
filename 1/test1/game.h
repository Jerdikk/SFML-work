#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <SFML/Graphics.hpp>

class Game: private sf::NonCopyable
{
public:
             Game();
        void run();
private:
        void processEvents();
        void handlePlayerInput(sf::Keyboard::Key key, bool IsPressed);
        void update(sf::Time deltaTime);
        void updateStatistics(sf::Time elapsedTime);
        void render();

        sf::RenderWindow mWindow;
        sf::Texture  mTexture;
        sf::Sprite   mPlayer;
        sf::Font	mFont;
		sf::Text	mStatisticsText;
		sf::Time	mStatisticsUpdateTime;
		std::size_t	mStatisticsNumFrames;

        bool mIsMovingUp;
        bool mIsMovingDown;
        bool mIsMovingLeft;
        bool mIsMovingRight;
};

#include <sstream>

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string toString(const T& value);

template <typename T>
std::string toString(const T& value)
{
    std::stringstream stream;
    stream << value;
    return stream.str();
}

template <typename T>
std::wstring towString(const T& value);

template <typename T>
std::wstring towString(const T& value)
{
    std::wstringstream stream;
    stream << value;
    return stream.str();
}


#endif // GAME_INCLUDED
