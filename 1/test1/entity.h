#ifndef ENTITY_H
#define ENTITY_H


class Entity
{
    public:
        sf::Vector2f getVelocity() const { return mVelocity; }
        void setVelocity(sf::Vector2f val) { mVelocity = val; }
        void setVelocity(float vx, float vy) { mVelocity.x = vx;mVelocity.y = vy; }
    protected:
    private:
        sf::Vector2f mVelocity;
};

#endif // ENTITY_H