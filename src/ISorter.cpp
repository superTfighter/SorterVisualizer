#include "ISorter.h"

std::vector<int> Sorter::sort(std::vector<int> input)
{
    std::vector<int> solution = this->sort_imp(input);

    return solution;
}

void Sorter::swap(int i, int j)
{
    int helper = _arr[i];
    _arr[i] = _arr[j];
    _arr[j] = helper;
}