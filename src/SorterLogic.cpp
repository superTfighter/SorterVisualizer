#include "SorterLogic.h"

// TODO:FIX!!!
sf::Image SorterLogic::generateImage()
{
    sf::Image image;

    if (this->sorter_imp == nullptr)
    {

        int chunksize = original_data.size() / 144;

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

                int value = original_data[iterator];

                // rgb(255,105,180)
                sf::Color color(scaleRange(value, 0, 255, 0, MAX_VALUE - 1), scaleRange(value, 0, 105, 0, MAX_VALUE - 1), scaleRange(value, 0, 180, 0, MAX_VALUE - 1), 255);

                image.setPixel(x, y, color);
            }
        }
    }
    else
    {
        image.create(16, 9, sf::Color::Blue);
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

    for (size_t i = 0; i < original_data.size(); i++)
    {
        original_data[i] = rand() % MAX_VALUE;
    }

    int a = 0;
}
