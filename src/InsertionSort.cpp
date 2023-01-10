#include "InsertionSort.h"

std::vector<int> InsertionSort::sort_imp(std::vector<int> input)
{
    this->_arr = input;

    int key, j;

    for (size_t i = 0; i < this->_arr.size(); i++)
    {
        key = _arr[i];
        j = i - 1;

        while (j >= 0 && _arr[j] > key)
        {
            _arr[j + 1] = _arr[j];
            j = j - 1;
        }
        _arr[j + 1] = key;
    }

    return this->_arr;
}

std::string InsertionSort::to_string()
{
    return "Insertion sort";
}
