#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "entity.h"
#include "ResourceManager.h"


class Aircraft : public Entity
{
    public:
        enum Type
        {
            Eagle,
            Raptor
        };
        Aircraft(Type type, const TextureHolder& textures);
        
    protected:
    private:
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

        Type mType;
        sf::Sprite mSprite;
};

#endif // AIRCRAFT_H
