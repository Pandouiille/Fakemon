#include "enemy.h"

enemy::enemy(const sf::Texture& texture, sf::IntRect test, int PV) : entity(texture)
{
	this->sprite.scale(0.7, 0.7);
	this->sprite.setTextureRect(test);
	this->PV_Pkmn = PV;
}



void enemy::enemySetPosition(float x, float y)
{
	this->sprite.setPosition(x, y);
}

void enemy::enemyMouvement()
{
	float elapsed1 = clock.getElapsedTime().asSeconds();
	//std::cout << elapsed1 << std::endl;
	if (elapsed1 >= 5)
	{
		int random_variable = std::rand() % 3 + 1;
		std::cout << "Random value on [0 " << RAND_MAX << "]: " << random_variable << '\n';
		if (random_variable == 1)
		{
			sprite.move(0.f, -10);
		}
		if (random_variable == 2)
		{
			sprite.move(0.f, 10);
		}
		if (random_variable == 3)
		{
			sprite.move(10, 0);
		}
		if (random_variable == 4)
		{
			sprite.move(10, 0);
		}

		std::cout << "�a fait 5s" << std::endl;
		clock.restart();
	}
	//this->sprite.move(0.f, 0.7);
	//this->sprite.setPosition(600.f, 600.f);

}

int enemy::getDamage()
{
	this->PV_Pkmn = this->PV_Pkmn - 1;
	std::cout << this->PV_Pkmn << std::endl;
	if (this->PV_Pkmn <= 0)
	{
		return 1;
	}
}
