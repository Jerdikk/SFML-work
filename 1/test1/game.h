#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <SFML/Graphics.hpp>

class Game
{
public:
             Game();
        void run();
private:
        void processEvents();
        void handlePlayerInput(sf::Keyboard::Key key, bool IsPressed);
        void update(sf::Time deltaTime);
        void render();

        sf::RenderWindow mWindow;
        sf::CircleShape mPlayer;
        bool mIsMovingUp;
        bool mIsMovingDown;
        bool mIsMovingLeft;
        bool mIsMovingRight;
};

#endif // GAME_INCLUDED
