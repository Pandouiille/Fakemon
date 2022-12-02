#include "entity.h"

entity::entity(const sf::Texture &texture) : _texture(texture), sprite(texture)
{
    
}

sf::Sprite& entity::getSprite(void)
{
    return this->sprite;
}

const sf::Sprite& entity::getSprite(void) const
{
    return this->sprite;
}
