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

    std::vector<int> sort();
    virtual std::string to_string() = 0;

    bool isRunning;

    void setArray(std::vector<int> input)
    {
        this->_arr = std::vector<int>(input.size());
        std::copy(input.begin(),input.end(),this->_arr.begin());
    }

private:
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;

protected:
    virtual std::vector<int> sort_imp() = 0;

    std::vector<int> _arr;
    void swap(int i, int j);
};