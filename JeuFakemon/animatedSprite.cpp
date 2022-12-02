#include "animatedSprite.h"

animatedSprite::animatedSprite(const sf::Texture& texture, std::vector < std::vector<sf::IntRect>> animation_position) : entity(texture)
{
	this->animation_count = 0;
	this->animation_position = animation_position;
	this->direction = 0;

	if (this->animation_position.size() <= 0)
		throw;

	this->sprite.setTextureRect(this->animation_position[0][this->animation_count]);
}

void animatedSprite::nextAnimation()
{
	this->animation_count++;

	if (this->animation_count >= this->animation_position[direction].size())
		this->animation_count = 0;
	if (this->direction == 4)
	{
		this->animation_count = 0;
	}

	this->sprite.setTextureRect(animation_position[direction][this->animation_count]);
}