#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <shellapi.h>
#include "entity.h"
#include "hero.h"

class game
{
private:
	int pos, pos_O;
	bool pressed, theselect;

	sf::RenderWindow window;
	sf::RectangleShape* winclose;
	sf::Font* font;
	sf::Texture* image;
	sf::Sprite* bg;
	sf::Texture* map;
	sf::Music* music;

	sf::Vector2i pos_mouse;
	sf::Vector2f mouse_coord;

	std::vector<const char*> options;
	std::vector<sf::Vector2f> coords;
	std::vector<sf::Text> texts;
	std::vector<std::size_t> sizes;

	std::vector<const char*> options_O;
	std::vector<sf::Vector2f> coords_O;
	std::vector<sf::Text> texts_O;
	std::vector<std::size_t> sizes_O;




public: 
	game(void);

	void ResizeView(const sf::RenderWindow& window, sf::View& view);

	bool windowIsOpen();
	void windowGame(hero hero_pos);
	
	void clear();
	void load_map();
	void display();
	void set_values();
	int loop_events();
	void draw_all();
	int run_menu();
	void draw_options();
	int loop_events_options();
	int run_options();
	void set_values_options();


	void drawEntity(const entity&);

};

