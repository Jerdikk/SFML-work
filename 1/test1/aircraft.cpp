#include "aircraft.h"

Aircraft::Aircraft(Type type, const TextureHolder& textures): mType(type)
{
    //ctor
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);

}
