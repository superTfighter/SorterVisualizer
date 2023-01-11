#pragma once
#include "SFML/Graphics.hpp"
#include "SorterLogic.h"

class Display
{

public:
    Display(sf::RenderWindow *window)
    {
        this->window = window;

        if (!font.loadFromFile("arial.ttf"))
        {
            throw "Error loading font!";
        }

        sorter_name_text.setFont(font);
        sorter_name_text.setCharacterSize(12);
        sorter_name_text.setFillColor(sf::Color::Red);
    }

    sf::RenderWindow *window;
    void renderLoop();

private:
    sf::Font font;
    sf::Text sorter_name_text;

    sf::Sprite numbers_sprite;
    sf::Texture numbers_texture;

    SorterLogic logic;

    void handleWindowEvents(sf::Event event);
    void draw();
    void runLogic();
};