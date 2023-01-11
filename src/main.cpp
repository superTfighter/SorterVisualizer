#include "Display.h"
#include <SFML/Graphics.hpp>

int main()
{
    time(NULL); // For better random generation

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Sorter Visualizer!");
    Display display(&window);

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        window.clear();
        display.renderLoop();
        window.display();
    }

    return 0;
}