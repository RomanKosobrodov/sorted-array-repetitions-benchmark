#include <catch2/catch_test_macros.hpp>
#include "generator.hpp"
#include <algorithm>

TEST_CASE("test problem generator")
{
    SECTION("single element is generated")
    {
        std::vector<int> v;
        int target{-1};
        generate(v, 1, 2, target, 342746);
        REQUIRE(v.size() == 1);
        CHECK(v.front() == target);
    }
    SECTION("arbitrary problem is generated")
    {
        std::vector<int> v;
        int target{-1};
        const std::size_t num_elements = 100;
        const std::size_t repetitions = 5;
        generate(v, num_elements, repetitions, target, 321);
        CHECK(v.size() > (num_elements - 1) * repetitions);
        CHECK(v.size() < num_elements * repetitions);
        auto target_count = std::count(v.begin(), v.end(), target);
        CHECK(target_count < repetitions);

        std::vector<int> sorted(v);
        std::sort(v.begin(), v.end());
        CHECK(sorted == v);
    }
}