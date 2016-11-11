#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <entity.h>


class Aircraft : public Entity
{
    public:
        enum Type
        {
            Eagle,
            Raptor
        };
        explicit Aircraft(Type type);
    protected:
    private:
        Type mType;
};

#endif // AIRCRAFT_H
