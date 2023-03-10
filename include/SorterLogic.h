#pragma once
#include "ISorter.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "SFML/Graphics.hpp"
#include <thread>
#include <vector>
#include <iostream>
#include "math.h"
#include <random>

#define SAMPLE_SIZE 920880 // TODO DINAMIC, this currently equals to a 1280x720 sample size
#define MAX_VALUE 50000

class SorterLogic
{

public:
    SorterLogic()
    {
        this->sorter_imp = nullptr;

        original_data = std::vector<int>(SAMPLE_SIZE);
        this->generateRandomData();
    }

    Sorter *sorter_imp;
    
    bool isRunning();  

    sf::Image generateImage();
    void setSorterImp();
    void generateRandomData();
    void reset();

private:
    std::vector<int> original_data;
    bool running;
  
    int scaleRange(int value, int range_min, int range_max, int value_min, int value_max);
    void generateRandomDataThreadTask();

    SelectionSort selection_s;
    BubbleSort bubble_s;
    InsertionSort insertion_s;
    QuickSort quick_s;
    HeapSort heap_s;
    
};