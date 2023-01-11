#pragma once
#include "ISorter.h"

class BubbleSort : public Sorter
{

public:
    std::string to_string();

private:
    std::vector<int> sort_imp();
};