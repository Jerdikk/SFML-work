#include "aircraft.h"

Aircraft::Aircraft(Type type): mType(type)
{
    //ctor
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);

}
