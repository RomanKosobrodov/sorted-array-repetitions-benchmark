#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>

inline int brute_force(const std::vector<int> &v, std::size_t k)
{
    if (v.empty())
    {
        throw std::runtime_error("vector is empty");
    }

    if (k < 1)
    {
        throw std::runtime_error("invalid k");
    }

    if (v.size() < k)
    {
        return v.front();
    }

    auto it0 = v.begin();
    auto it1 = it0 + k - 1;
    for (std::size_t p = 0; p < v.size() / k - 1; ++p)
    {
        if (*it0 != *it1)
        {
            return *it0;
        }

        it0 += k;
        it1 += k;
    }

    return *it1 == v.back() ? *it0 : v.back();
}