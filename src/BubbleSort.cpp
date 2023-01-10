#include "BubbleSort.h"

std::vector<int> BubbleSort::sort_imp(std::vector<int> input)
{
    this->_arr = input;

    for (size_t i = 0; i < this->_arr.size() - 1; i++)
    {
        for (size_t j = 0; j < this->_arr.size() - i - 1; j++)
        {
            if (_arr[j] > _arr[j + 1])
                this->swap(j, j + 1);
        }
    }

    return this->_arr;
}

std::string BubbleSort::to_string()
{
    return "Bubble sort" ;
} 
