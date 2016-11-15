#include "aircraft.h"

Textures::ID toTextureID(Aircraft::Type type)
{
	switch (type)
	{
	case Aircraft::Eagle:
		return Textures::Eagle;
		break;
	case Aircraft::Raptor:
		return Textures::Raptor;
		break;
	default:
		return Textures::Eagle;
		break;
	}
}

Aircraft::Aircraft(Type type, const TextureHolder& textures):
	mType(type), mSprite(textures.get(toTextureID(type)))
{
    // Устанавливаем центр спрайта в качестве Origin
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);

}
