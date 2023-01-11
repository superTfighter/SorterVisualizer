#include "Display.h"
#include <SFML/Graphics.hpp>

int main()
{
    time(NULL); // For better random generation

    sf::RenderWindow window(sf::VideoMode(960, 540), "Sorter Visualizer!");
    Display display(&window);

    while (window.isOpen())
    {
        window.clear();
        display.renderLoop();
        window.display();
    }

    return 0;
}