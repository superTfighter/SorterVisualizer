#include "HeapSort.h"

std::vector<int> HeapSort::sort_imp()
{
    this->heapSort(this->_arr.size());

    return this->_arr;
}

std::string HeapSort::to_string()
{
    return "Heap sort";
}

void HeapSort::heapSort(int N)
{
    for (int i = (N / 2 - 1); i >= 0; i--)
    {
        this->heapify(N, i);
    }

    for (int i = (N - 1); i > 0; i--)
    {
        this->swap(0, i);
        this->heapify(i, 0);
    }
}

void HeapSort::heapify(int N, int i)
{
    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l<N &&this->_arr[l]> this->_arr[largest])
    {
        largest = l;
    }

    if (r<N &&this->_arr[r]> this->_arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {

        this->swap(i, largest);
        heapify(N, largest);
    }
}
