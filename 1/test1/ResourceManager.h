#ifndef RESOURCEMANAGER_H_INCLUDED
#define RESOURCEMANAGER_H_INCLUDED

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

#include <SFML/Graphics.hpp>

namespace Textures
{
    enum ID {
        Landscape,
        Airplane,
        Missile
        };
}

template <typename Resource, typename Identifier>
class ResourceHolder
{
    public:
        void load(Identifier id, const std::string& filename);
        template <typename Parameter>
        void load(Identifier id, const std::string& filename, const Parameter& secondParam);
        Resource& get(Identifier id);
        const Resource& get(Identifier id) const;

    private:
        void insertResource(Identifier id, std::unique_ptr<Resource> resource);

        std::map <Identifier, std::unique_ptr<Resource>> mResourceMap;

};

#include "ResourceManager.inl"



#endif // RESOURCEMANAGER_H_INCLUDED
