#pragma once
#include "ISorter.h"

class QuickSort : public Sorter
{

public:
    std::string to_string();

private:
    std::vector<int> sort_imp(std::vector<int> input);

    void qSort(int low, int high);
    int partition(int low, int high);
};