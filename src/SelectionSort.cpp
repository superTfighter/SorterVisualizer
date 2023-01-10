#include "SelectionSort.h"

std::vector<int> SelectionSort::sort_imp(std::vector<int> input)
{
    this->_arr = input;

    int min_idx;

    for (size_t i = 0; i < this->_arr.size() - 1; i++)
    {
        min_idx = i;

        for (size_t j = i + 1; j < this->_arr.size(); j++)
        {
            if (this->_arr[j] < this->_arr[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
        {
            this->swap(min_idx, i);
        }
    }

    return this->_arr;
}

std::string SelectionSort::to_string()
{
    return "Selection sort";
}


