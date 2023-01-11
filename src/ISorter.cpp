#include "ISorter.h"

std::vector<int> Sorter::sort()
{
    this->isRunning = true;

    std::vector<int> solution = this->sort_imp();

    this->isRunning = false;

    return solution;
}

void Sorter::swap(int i, int j)
{
    int helper = _arr[i];
    _arr[i] = _arr[j];
    _arr[j] = helper;
}