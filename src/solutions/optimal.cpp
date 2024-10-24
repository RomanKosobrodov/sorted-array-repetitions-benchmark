#include "optimal.hpp"

int lower_bound(const std::vector<int> &nums, int target)
{
    int low = 0, high = nums.size();

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}

int upper_bound(const std::vector<int> &nums, int target)
{
    int low = 0, high = nums.size();

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] <= target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}

int solve(std::vector<int> &nums, int k)
{
    int n = nums.size();

    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        bool left = false;
        int ubIndex = upper_bound(nums, nums[mid]);

        if ((ubIndex - low) % k == 0)
        {
            left = true;
        }

        if (left)
        {
            low = ubIndex;
        }
        else
        {
            high = lower_bound(nums, nums[mid]) - 1;
        }
    }

    return nums[low];
}