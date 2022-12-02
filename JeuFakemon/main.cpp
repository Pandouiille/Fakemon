#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "game.h"
#include "animatedSprite.h"
#include "entity.h"
#include "hero.h"


int main()
{
	bool firstPassage = true;
	int j = 0;
	int pokemonDead;

	game g;
	int state = 0;

	std::vector <enemy> allEnemy;
	std::srand(std::time(nullptr));
	float coordEnemyX[10];
	float coordEnemyY[10];
	coordEnemyX[0] = 600.f;
	coordEnemyY[0] = 400.f;
	coordEnemyX[1] = 800.f;
	coordEnemyY[1] = 400.f;
	coordEnemyX[2] = 1000.f;
	coordEnemyY[2] = 400.f;

	sf::Texture texture;
	sf::Texture enemy_Texture;
	if (!texture.loadFromFile(DOOM_TEXTURE))
	{
		printf("error");
		// error...
	}

	hero doom = hero(texture);
	enemy bulbizar = enemy(enemy_Texture, BULBISAR, 2);
	allEnemy.push_back(bulbizar);
	enemy dracofeu = enemy(enemy_Texture, DRACOFEU, 2);
	allEnemy.push_back(dracofeu);
	enemy roucool = enemy(enemy_Texture, ROUCOOL, 2);
	allEnemy.push_back(roucool);

	int count = 0;
	g.set_values();
	g.set_values_options();
	g.load_map();
	while (g.windowIsOpen())
	{
		g.clear();
		if (state == 0)
		{
			state = g.run_menu();
		}
		else if (state == 1) {
			g.windowGame(doom);

			doom.heroMouvement();
			if (firstPassage == true) {

				for (auto& i : allEnemy)
				{

					g.drawEntity(i);
					i.enemySetPosition(coordEnemyX[j], coordEnemyY[j]);
					j++;

				}
				j = 0;
				firstPassage = false;
			}
			else {
				for (auto& i : allEnemy)
				{

					g.drawEntity(i);
					pokemonDead = doom.dealDamage(i);
					if (pokemonDead == 1)
					{
						//allEnemy.erase(allEnemy.begin());
					}
					doom.heroShooting(i);
					i.enemyMouvement();

				}

			}
			if (count % 20 == 0)
			{
				doom.nextAnimation();
				count = 0;
			}
			count++;
			g.drawEntity(doom);
		}
		else if (state == 2)
		{
			state = g.run_options();
		}
		g.display();
	}

	return 0;
}