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
        explicit Aircraft(Type type, const TextureHolder& textures);
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    protected:
    private:
        Type mType;
        sf::Sprite mSprite;
};

#endif // AIRCRAFT_H
