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

private:
    std::vector<int> original_data;
    bool running;

    void generateRandomData(int maxValue, std::vector<int> &vector);
    int scaleRange(int value, int range_min, int range_max, int value_min, int value_max);
};