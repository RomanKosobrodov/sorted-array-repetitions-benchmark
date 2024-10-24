#include "benchmark.hpp"
#include "brute_force.hpp"
#include "optimal.hpp"
#include <format>
#include <iostream>

int main(int argc, char *argv[])
{
    const size_t repetitions = 5;
    const size_t runs = 10000;

    std::cout << "\"elements\", \"brute force\", \"optimal\"\n";
    for (const auto &num_elements : {16, 32, 64, 128, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536})
    {
        double elapsed_brute_force = benchmark(num_elements, repetitions, runs, brute_force);
        double elapsed_optimal = benchmark(num_elements, repetitions, runs, solve);
        std::cout << std::format("{:5d}, {:.1f},  {:.1f}\n", num_elements, elapsed_brute_force, elapsed_optimal);
    }
}