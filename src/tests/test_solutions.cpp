#include <catch2/catch_test_macros.hpp>
#include "brute_force.hpp"
#include "generator.hpp"
#include "optimal.hpp"
#include <algorithm>

TEST_CASE("brute_force returns expected results")
{
    std::vector<int> v;
    int target{-1};
    const std::size_t num_elements = 7;
    const std::size_t reps = 3;
    generate(v, num_elements, reps, target, 3834);

    int result = brute_force(v, reps);
    CHECK(target == result);
}

TEST_CASE("optimal returns expected results")
{
    std::vector<int> v;
    int target{-1};
    const std::size_t num_elements = 7;
    const std::size_t reps = 3;
    generate(v, num_elements, reps, target, 3834);

    int result = solve(v, reps);
    CHECK(target == result);
}