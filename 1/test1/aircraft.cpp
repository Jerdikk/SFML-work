#include "aircraft.h"

Aircraft::Aircraft(Type type): mType(type)
{
    //ctor
}

Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);

}
