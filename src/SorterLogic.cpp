#include "SorterLogic.h"

sf::Image SorterLogic::generateImage()
{
    sf::Image image;

    if (this->sorter_imp == nullptr)
    {
        image.create(1280, 720, sf::Color::Black);

        int iterator = 0;

        for (size_t y = 0; y < image.getSize().y; y++)
        {
            for (size_t x = 0; x < image.getSize().x; x++)
            {
                iterator = (y * (image.getSize().x - 1) + x);

                int value = original_data[iterator];

                // rgba(255,255,255,255)
                sf::Color color(
                    scaleRange(value, 0, 255, 0, MAX_VALUE - 1),
                    scaleRange(value, 0, 255, 0, MAX_VALUE - 1),
                    scaleRange(value, 0, 255, 0, MAX_VALUE - 1),
                    255);

                image.setPixel(x, y, color);
            }
        }
    }
    else
    {
        image.create(1280, 720, sf::Color::Black);

        int iterator = 0;

        for (size_t y = 0; y < image.getSize().y; y++)
        {
            for (size_t x = 0; x < image.getSize().x; x++)
            {
                iterator = (y * (image.getSize().x - 1) + x);

                int value = sorter_imp->getArray()[iterator];

                // rgba(255,255,255,255)
                sf::Color color(
                    scaleRange(value, 0, 255, 0, MAX_VALUE - 1),
                    scaleRange(value, 0, 255, 0, MAX_VALUE - 1),
                    scaleRange(value, 0, 255, 0, MAX_VALUE - 1),
                    255);

                image.setPixel(x, y, color);
            }
        }
    }

    return image;
}

void SorterLogic::setSorterImp()
{
    this->sorter_imp = &selection_s;

    
}

void SorterLogic::generateRandomData()
{
    std::thread(&SorterLogic::generateRandomDataThreadTask, this).detach();
}

int SorterLogic::scaleRange(int value, int range_min, int range_max, int value_min, int value_max)
{
    return (((range_max - range_min) * (value - value_min)) / (value_max - value_min)) + range_min;
}

void SorterLogic::generateRandomDataThreadTask()
{

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(0, MAX_VALUE);

    for (size_t i = 0; i < original_data.size(); i++)
    {
        original_data[i] = distr(generator);
    }

    int a = 0;
}
