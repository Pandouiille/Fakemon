#pragma once

#include "animatedSprite.h"
#include "enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


#define DOOM_TEXTURE "hero.png"
#define DOOM_ANIMATION_MOUVEMENT																\
{\
	{\
		sf::IntRect(0, 0, 23, 34), sf::IntRect(22, 1, 23, 34), sf::IntRect(48, 1, 23, 34), sf::IntRect(72, 1, 23, 34)\
	},\
	{ \
		sf::IntRect(0, 107, 23, 34), sf::IntRect(22, 107, 23, 34), sf::IntRect(47, 107, 23, 34), sf::IntRect(71, 107, 23, 34)\
	},\
	{\
		sf::IntRect(0, 36, 23, 34), sf::IntRect(21, 36, 23, 34), sf::IntRect(47, 36, 23, 34), sf::IntRect(70, 36, 25, 34)\
	},\
	{\
		sf::IntRect(0, 72, 24, 34), sf::IntRect(24, 72, 24, 34), sf::IntRect(46, 72, 24, 34), sf::IntRect(71, 72, 24, 34)\
	},\
	{\
		sf::IntRect(0, 281, 36, 46), sf::IntRect(0, 281, 36, 46), sf::IntRect(0, 281, 36, 46), sf::IntRect(0, 281, 36, 46)\
	}\
}\



class hero : public animatedSprite
{
public:
	hero(const sf::Texture& texture);
	~hero();
	void heroMouvement();
	void heroShooting(enemy&);
	int dealDamage(enemy& pokemon);
protected:
	bool isOnRange = false;
	bool isPress = false;
	int oldDirection;

	sf::Clock takeDamage;

};

