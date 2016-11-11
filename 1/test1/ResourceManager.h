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

class TextureHolder
{
    public:
        void load(Textures::ID id, const std::string& filename);
        sf::Texture& get(Textures::ID id);
        const sf::Texture& get(Textures::ID id) const;

    private:
        std::map <Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;

};


#endif // RESOURCEMANAGER_H_INCLUDED
