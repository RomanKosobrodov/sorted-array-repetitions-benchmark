#pragma once
#include "generator.hpp"
#include <assert.h>
#include <chrono>
#include <iostream>
#include <stdexcept>

template <typename Solution>
double benchmark(std::size_t num_elements, std::size_t repetitions, std::size_t runs, Solution &&s)
{
    double elapsed{0};
    std::vector<int> v;
    int target{-1};
    for (std::size_t k = 0; k < runs; ++k)
    {
        const unsigned int seed = static_cast<int>(k * num_elements);
        generate(v, num_elements, repetitions, target, seed);

        const auto t0 = std::chrono::high_resolution_clock::now();
        int result = s(v, int(repetitions));
        const auto dt = std::chrono::high_resolution_clock::now() - t0;
        elapsed += static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count());

        if (result != target)
        {
            std::runtime_error("invalid solution");
        }
    }
    return elapsed / static_cast<double>(runs);
}