#include "iostream"
#include <string>
#include <sstream>
#include "vector"
#include "ISorter.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "Colormod.h"
#include <thread>

#include <SFML/Graphics.hpp>

#define SAMPLE_SIZE 20000
#define MAX_VALUE 50000

int iter = 0;
sf::Texture texture;
std::vector<Sorter *> sorters;

void printData(std::vector<int> data)
{

    for (size_t i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << "  ";
    }

    std::cout << std::endl;
}

void generateRandomData(int maxValue, std::vector<int> &vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        vector[i] = rand() % maxValue;
    }
}

void generateData(std::vector<int> &vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        vector[i] = vector.size() - i;
    }
}

void ClearConsole()
{
    printf("\033[2J");
    printf("\033[K");
}

void sortData(std::vector<Sorter *> sorters, std::vector<int> original)
{

    std::vector<int> clone = std::vector<int>(original.size());
    std::copy(original.begin(), original.end(), clone.begin());

    for (size_t i = 0; i < sorters.size(); i++)
    {
        iter = i;
        sorters[i]->sort(clone);
    }
}

int scaleRange(int value, int range_min, int range_max, int value_min, int value_max)
{
    return (((range_max - range_min) * (value - value_min)) / (value_max - value_min)) + range_min;
}

sf::Image generateImage(std::vector<int> data)
{
    sf::Image image;

    image.create(16, 9, sf::Color::Black);

    if (data.size() > 0)
    {
        int chunksize = data.size() / 144;

        image.create(chunksize * 16, chunksize * 9, sf::Color::Black);

        int iterator = 0;

        for (size_t y = 0; y < chunksize * 9; y++)
        {
            for (size_t x = 0; x < chunksize * 16; x++)
            {
                iterator = (y * 16 + x);

                // TODO:FIX, Quick and dirty bug fix!
                if (iterator > SAMPLE_SIZE)
                    iterator = SAMPLE_SIZE - 1;

                int value = data[iterator];

                // rgb(255,105,180)
                sf::Color color(scaleRange(value, 0, 255, 0, MAX_VALUE - 1), scaleRange(value, 0, 105, 0, MAX_VALUE - 1), scaleRange(value, 0, 180, 0, MAX_VALUE - 1), 255);

                image.setPixel(x, y, color);
            }
        }
    }

    return image;
}

int main()
{
    time(NULL);

    sf::Font font;

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Error loading font!" << std::endl;

        return 1;
    }

    sf::RenderWindow window(sf::VideoMode(960, 540), "Sorter Visualizer!");

    sf::Text sorter_name_text;
    sorter_name_text.setFont(font);
    sorter_name_text.setCharacterSize(24);
    sorter_name_text.setFillColor(sf::Color::Red);

    std::vector<int> original = std::vector<int>(SAMPLE_SIZE);
    std::vector<int> sorted = original;

    generateRandomData(MAX_VALUE, original);

    SelectionSort selection_s;
    BubbleSort bubble_s;
    InsertionSort insertion_s;
    QuickSort quick_s;
    HeapSort heap_s;

    sorters.push_back(&selection_s);
    sorters.push_back(&bubble_s);
    sorters.push_back(&insertion_s);
    sorters.push_back(&quick_s);
    sorters.push_back(&heap_s);

    std::thread t1(sortData, (sorters), (original));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                t1.join();
                window.close();
            }

            sorter_name_text.setString(sorters[iter]->to_string());

            sf::Sprite sprite;

            sf::Image image = generateImage(sorters[iter]->getArray());
            texture.loadFromImage(image);
            sprite.setTexture(texture);
            sprite.scale(window.getView().getSize().x / sprite.getLocalBounds().width, window.getView().getSize().y / sprite.getLocalBounds().height);

            window.clear(sf::Color::Black);

            window.draw(sprite);
            window.draw(sorter_name_text);

            window.display();
        }
    }

    if (t1.joinable())
        t1.join();

    return 0;
}