#pragma once
#include "ISorter.h"

class InsertionSort : public Sorter
{

public:
    std::string to_string();

private:
    std::vector<int> sort_imp();
};