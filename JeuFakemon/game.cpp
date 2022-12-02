#include "game.h"
#include "hero.h"

static const float VIEW_HEIGHT = 512.0f;

game::game() : window(sf::VideoMode(1920, 1080), "PokeDoom")
{
	this->window.setFramerateLimit(60);
    winclose = new sf::RectangleShape();
    font = new sf::Font();
    image = new sf::Texture();
    map = new sf::Texture();
    bg = new sf::Sprite();
    music = new sf::Music();
    
    
}


bool game::windowIsOpen()
{
	return this->window.isOpen();
}

void game::ResizeView(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x / window.getSize().y);
    view.setSize(VIEW_HEIGHT * 1, VIEW_HEIGHT);
}

void game::windowGame(hero hero_pos)
{
    sf::Sprite hero_posi;
	sf::Event event;
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
    bg->setTexture(*map);
    bg->setScale(1, 1);
    this->window.draw(*bg);

	while (this->window.pollEvent(event))
	{
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::Resized:
            ResizeView(window, view);
            break;
        }
        window.setView(view);
	}
    hero_posi = hero_pos.getSprite();
    view.setCenter(hero_posi.getPosition());
    window.setView(view);
}


void game::clear()
{
	this->window.clear();
}

void game::load_map()
{
    map->loadFromFile("./map.png");
}


void game::display()
{
	this->window.display();
}

void game::drawEntity(const entity &entity)
{
	this->window.draw(entity.getSprite());
}

void game::set_values() {
    
    this->window.setPosition(sf::Vector2i(0, 0));

    pos = 0;
    pressed = theselect = false;
    font->loadFromFile("./AmazDooMLeft.ttf");
    image->loadFromFile("./Doom_menu.jpg");
    if (!music->openFromFile("music.ogg")) {
        std::cout << "error" << std::endl;
    }
    music->setVolume(1);
    music->play();

    bg->setTexture(*image);
    bg->setScale(1.5, 1.5);

    pos_mouse = { 0,0 };
    mouse_coord = { 0, 0 };

    options = { "PokeDoom", "Play", "Options", "About", "Quit" };
    texts.resize(5);
    coords = { {650,60},{200,400},{200,500},{200,600},{200,700} };
    sizes = { 250,100,100,100,100 };


    for (std::size_t i{}; i < texts.size(); ++i) {
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setOutlineColor(sf::Color::Red);
        texts[i].setOrigin(1.f, 1.f);
        texts[i].setPosition(coords[i]);
    }
    texts[1].setOutlineThickness(10);
    pos = 1;

    winclose->setSize(sf::Vector2f(34.5, 39));
    winclose->setPosition(1767, 58.5);
    winclose->setFillColor(sf::Color::Transparent);

}
int game::loop_events() {
    sf::Event event;

    while (this->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->window.close();
        }

        pos_mouse = sf::Mouse::getPosition(window);
        mouse_coord = this->window.mapPixelToCoords(pos_mouse);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
            if (pos < 4) {
                ++pos;
                pressed = true;
                texts[pos].setOutlineThickness(10);
                texts[pos - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
            if (pos > 1) {
                --pos;
                pressed = true;
                texts[pos].setOutlineThickness(10);
                texts[pos + 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
            theselect = true;
            if (pos == 4) {
                this->window.close();
            }
            if (pos == 1) {
                return 1;
            }
            if (pos == 2) {
                texts[2].setOutlineThickness(0);
                return 2;
            }
            if (pos == 3) {
                ShellExecute(0, 0, L"https://github.com/Cyriansavary/PokeDoom", 0, 0, SW_SHOW);
            }
        }
    }
}


void game::draw_all() {
    this->window.clear();
    this->window.draw(*bg);
    for (auto t : texts) {
        this->window.draw(t);
    }
    this->window.display();
}

int game::run_menu() {
    int state = 0;
    while (this->window.isOpen()) {
        state = loop_events();
        draw_all();
        if (state != 0)
        {
            return state;
        }
    }
}
void game::draw_options() {
    this->window.clear();
    this->window.draw(*bg);
    for (auto t : texts_O) {
        this->window.draw(t);
    }

}
int game::loop_events_options() {
    sf::Event event;

    while (this->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->window.close();
        }
        printf("%d\n", pos_O);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
            if (pos_O < 3) {
                ++pos_O;
                pressed = true;
                texts_O[pos_O].setOutlineThickness(10);
                texts_O[pos_O - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
            if (pos_O > 1) {
                --pos_O;
                pressed = true;
                texts_O[pos_O].setOutlineThickness(10);
                texts_O[pos_O + 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
            theselect = true;
            if (pos_O == 3) {
                return 0;
            }
            if (pos_O == 1) {
                
            }
            if (pos_O == 2) {
                
                
            }
        }
    }
    return 2;
}

void game::set_values_options() {
    bg->setTexture(*image);
    bg->setScale(1.5, 1.5);
    pos_mouse = { 0,0 };
    mouse_coord = { 0, 0 };

    options_O = { "Option", "Sound", "Graphic", "Return"};
    texts_O.resize(4);
    coords_O = { {750,60},{200,400},{200,500},{200,600} };
    sizes_O = { 250,100,100,100 };


    for (std::size_t i{}; i < texts_O.size(); ++i) {
        texts_O[i].setFont(*font);
        texts_O[i].setString(options_O[i]);
        texts_O[i].setCharacterSize(sizes_O[i]);
        texts_O[i].setOutlineColor(sf::Color::Red);
        texts_O[i].setOrigin(1.f, 1.f);
        texts_O[i].setPosition(coords_O[i]);
    }
    pos_O = 1;
    texts_O[1].setOutlineThickness(10);

    winclose->setSize(sf::Vector2f(34.5, 39));
    winclose->setPosition(1767, 58.5);
    winclose->setFillColor(sf::Color::Transparent);
}

int game::run_options() {
   
        draw_options();
		return loop_events_options();
}
