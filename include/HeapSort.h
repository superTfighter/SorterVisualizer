#pragma once
#include "ISorter.h"

class HeapSort : public Sorter
{

public:
    std::string to_string();

private:
    std::vector<int> sort_imp(std::vector<int> input);

    void heapSort(int N);
    void heapify(int N, int i);
};
