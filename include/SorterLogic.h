#pragma once
#include "ISorter.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "SFML/Graphics.hpp"

#define SAMPLE_SIZE 20000
#define MAX_VALUE 50000

class SorterLogic
{

public:

    SorterLogic()
    {
        this->sorter_imp = nullptr;

        original_data = std::vector<int>(SAMPLE_SIZE);
        this->generateRandomData(MAX_VALUE,original_data);
    }


    Sorter *sorter_imp;

   /*  std::vector<int> getOriginalData();
    bool isRunning();
 */
    sf::Image generateImage();
    /* {
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
    } */

private:
    std::vector<int> original_data;
    bool running;

    void generateRandomData(int maxValue, std::vector<int> &vector);


   // int scaleRange(int value, int range_min, int range_max, int value_min, int value_max);
    /*     {
            return (((range_max - range_min) * (value - value_min)) / (value_max - value_min)) + range_min;
        } */
};