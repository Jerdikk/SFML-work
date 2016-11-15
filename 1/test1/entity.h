#ifndef ENTITY_H
#define ENTITY_H

#include "scenenode.h"
#include <SFML/Graphics.hpp>

class Entity : public SceneNode
{
    public:
		sf::Vector2f getVelocity() const;
		void setVelocity(sf::Vector2f val);
		void setVelocity(float vx, float vy);
    protected:
    private:
		virtual void		updateCurrent(sf::Time dt);

        sf::Vector2f mVelocity;
};

#endif // ENTITY_H
