#include "QuickSort.h"

std::vector<int> QuickSort::sort_imp(std::vector<int> input)
{
    this->_arr = input;

    this->qSort(0, this->_arr.size() - 1);

    return this->_arr;
}

std::string QuickSort::to_string()
{
    return "Quick sort";
}

void QuickSort::qSort(int low, int high)
{
    if (low < high)
    {
        int pi = this->partition(low, high);

        qSort(low, pi - 1);
        qSort(pi + 1, high);
    }
}

int QuickSort::partition(int low, int high)
{
    int pivot = this->_arr[high];
    int i = (low - 1);

    for (size_t j = low; j <= high - 1; j++)
    {
        if (this->_arr[j] < pivot)
        {
            i++;
            this->swap(i, j);
        }
    }

    this->swap(i + 1, high);
    return i + 1;
}
