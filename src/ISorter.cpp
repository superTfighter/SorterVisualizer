#include "ISorter.h"

std::vector<int> Sorter::sort(std::vector<int> input)
{
    begin = std::chrono::steady_clock::now();

    std::vector<int> solution = this->sort_imp(input);

    end = std::chrono::steady_clock::now();

    std::cout << this->to_string() << " took: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    return solution;
}

void Sorter::swap(int i, int j)
{
    int helper = _arr[i];
    _arr[i] = _arr[j];
    _arr[j] = helper;
}