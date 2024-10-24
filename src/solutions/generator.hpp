#pragma once
#include <vector>
#include <random>

inline void generate(std::vector<int> &v, std::size_t num_elements, std::size_t k, int &target, unsigned int seed)
{
    if (k < 2)
    {
        v.clear();
        target = 0;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    gen.seed(seed);

    std::uniform_int_distribution<> target_index(0, static_cast<int>(num_elements) - 1);
    const std::size_t ind = target_index(gen);

    v.clear();
    v.reserve(num_elements * k);
    int previous = 0;
    for (std::size_t p = 0; p < num_elements; ++p)
    {
        std::uniform_int_distribution<> ud(previous + 1, static_cast<int>(num_elements) + previous + 1);
        previous = ud(gen);
        if (p != ind)
        {
            for (std::size_t q = 0; q < k; ++q)
            {
                v.push_back(previous);
            }
        }
        else
        {
            target = previous;
            std::uniform_int_distribution<> rep(1, static_cast<int>(k) - 1);
            for (int q = 0; q < rep(gen); ++q)
            {
                v.push_back(previous);
            }
        }
    }
}