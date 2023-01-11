#include "Display.h"
#include <SFML/Graphics.hpp>

//TODO: Stop thread execution on demand, colors in rendering, slow down faster implementation for presentation
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