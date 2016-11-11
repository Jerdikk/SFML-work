#include "ResourceManager.h"

void TextureHolder::load(Textures::ID id, const std::string& filename)
{
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    texture->loadFromFile(filename);

    mTextureMap.insert(std::make_pair(id, std::move(texture)));
}

sf::Texture& TextureHolder::get(Textures::ID id)
{
    auto found = mTextureMap.find(id);
    return *found->second;
}

const sf::Texture& TextureHolder::get(Textures::ID id) const
{
    auto found = mTextureMap.find(id);
    return *found->second;
}
