#pragma once
#include <SFML/Graphics.hpp>
#include "animatedSprite.h"


#define ENEMY_TEXTURE "enemy.png"
#define BULBISAR sf::IntRect(2, 2, 70, 68)
#define DRACOFEU sf::IntRect(4, 67, 68, 85)
#define ROUCOOL sf::IntRect(4, 203, 68, 85)
#define RAND_MAX 4

class enemy : public entity
{
private:
	sf::Clock clock;
	int PV_Pkmn;


public:

	enemy(const sf::Texture& texture, sf::IntRect test, int PV);
	void enemySetPosition(float x, float y);
	void enemyMouvement();
	int getDamage();


};

