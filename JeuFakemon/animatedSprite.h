#pragma once
#include <iostream>

#include "entity.h"

class animatedSprite : public entity
{
protected:
	size_t animation_count;
	std::vector < std::vector<sf::IntRect>> animation_position;
	int direction;

public:
	animatedSprite(const sf::Texture&, std::vector < std::vector<sf::IntRect>>);
	void nextAnimation();
};

