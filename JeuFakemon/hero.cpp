#include "hero.h"
#include <iostream>

hero::hero(const sf::Texture& texture) :
    animatedSprite(texture, std::vector<std::vector<sf::IntRect>>(DOOM_ANIMATION_MOUVEMENT))
{
    {
        this->sprite.scale(1, 1);
    }
}

hero::~hero()
{
}

void hero::heroMouvement()
{
    sf::Event event;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        sprite.move(0.f, -10);
        direction = 1;
        sprite.setTextureRect(this->animation_position[direction][this->animation_count]);
        oldDirection = 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        sprite.move(0.f, 10);
        direction = 0;
        sprite.setTextureRect(this->animation_position[direction][this->animation_count]);
        oldDirection = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        sprite.move(-10, 0.f);
        direction = 2;
        sprite.setTextureRect(this->animation_position[direction][this->animation_count]);
        oldDirection = 2;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        sprite.move(10, 0.f);
        direction = 3;
        sprite.setTextureRect(this->animation_position[direction][this->animation_count]);
        oldDirection = 3;
    }



}

void hero::heroShooting(enemy& pokemon)
{
    sf::Sprite pokemonEnemy = pokemon.getSprite();
    if (pokemonEnemy.getPosition().x < (this->sprite.getPosition().x + 100) && pokemonEnemy.getPosition().x >(this->sprite.getPosition().x - 100) &&
        pokemonEnemy.getPosition().y < (this->sprite.getPosition().y + 100) && pokemonEnemy.getPosition().y >(this->sprite.getPosition().y - 100))
    {
        isOnRange = true;

    }
    else
    {
        isOnRange = false;
    }

}

int hero::dealDamage(enemy& pokemon)
{
    int isDead = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        oldDirection = direction;
        direction = 4;
        sprite.setTextureRect(this->animation_position[direction][this->animation_count]);
        direction = oldDirection;
        float cd = takeDamage.getElapsedTime().asSeconds();
        if (isOnRange == true && cd >= 2)
        {
            std::cout << "TAKE DAMAGE" << std::endl;
            isDead = pokemon.getDamage();
            std::cout << isDead << " pv " << std::endl;
            takeDamage.restart();
        }

    }
    return isDead;
}