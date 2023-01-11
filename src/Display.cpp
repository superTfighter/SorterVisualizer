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

    switch (event.type)
    {
    case sf::Event::Closed:
        this->window->close();
        break;

    case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::S)
            this->logic.setSorterImp(); // Quick and dirty hack to set debug imp
        else if(event.key.code == sf::Keyboard::R)
            this->logic.generateRandomData();
        break;

    default:
        break;
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
        sorter_name_text.setString(this->logic.sorter_imp->to_string());

    sf::Image numbers_image = this->logic.generateImage();

    this->numbers_texture.loadFromImage(numbers_image);
    sprite.setTexture(this->numbers_texture);
    sprite.scale((float)window->getView().getSize().x /(float)numbers_image.getSize().x, (float)window->getView().getSize().y /(float)numbers_image.getSize().y);

    sprite.setPosition(0,0);
    
    this->numbers_sprite = sprite;
}
