#pragma once
#include <vector>
#include <chrono>
#include <iostream>

class Sorter
{
public:


    std::vector<int> getArray()
    {
        return this->_arr;
    }


    std::vector<int> sort(std::vector<int> input);
    virtual std::string to_string() = 0;

private:
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;

protected:
    virtual std::vector<int> sort_imp(std::vector<int> input) = 0;

    std::vector<int> _arr;
    void swap(int i, int j);
};