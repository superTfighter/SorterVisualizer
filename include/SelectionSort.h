#pragma once
#include "ISorter.h"
#include <algorithm>

class SelectionSort : public Sorter
{

public:
    std::string to_string();

private:
    std::vector<int> sort_imp(std::vector<int> input);
};
