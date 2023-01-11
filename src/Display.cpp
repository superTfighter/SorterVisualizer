#include "Display.h"

void Display::renderLoop()
{
    sf::Event event;

    while (window->pollEvent(event))
    {
        this->handleWindowEvents(event);
    }

    this->runLogic();

    this->draw();

    return;
}

void Display::handleWindowEvents(sf::Event event)
{

    if (event.type == sf::Event::Closed)
    {
        this->window->close();
    }

    return;
}

// Draw here, order is important!
void Display::draw()
{
    window->draw(numbers_sprite);
    window->draw(sorter_name_text);
   
}

void Display::runLogic()
{

    sf::Sprite sprite;

    if (this->logic.sorter_imp == nullptr)
        sorter_name_text.setString("Generate random numbers then choose a sorting method!");
    else
        sorter_name_text.setString("ASD");



    sf::Image numbers_image = this->logic.generateImage();

    this->numbers_texture.loadFromImage(numbers_image);

    sprite.setTexture(this->numbers_texture);
    sprite.scale(window->getView().getSize().x / sprite.getLocalBounds().width, window->getView().getSize().y / sprite.getLocalBounds().height);

    this->numbers_sprite = sprite;
}
