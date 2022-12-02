#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class entity
{
protected:
	sf::Sprite sprite;
	const sf::Texture& _texture;
	
public : 
	
	entity(const sf::Texture &texture);
	sf::Sprite& getSprite(void);
	const sf::Sprite& getSprite(void) const;
};

