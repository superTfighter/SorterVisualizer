#include "SorterLogic.h"

sf::Image SorterLogic::generateImage()
{
    sf::Image image;
    image.create(16, 9, sf::Color::Blue);

    return image;
}

void SorterLogic::generateRandomData(int maxValue, std::vector<int> &vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        vector[i] = rand() % maxValue;
    }
}