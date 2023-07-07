#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<int> findClosestElements(const std::vector<int> &nums, int k, int x)
{
    int n = nums.size();
    int left = 0, right = n - 1;

    // Binary search to find the closest element
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    // Initialize two pointers to expand around the closest element
    int low = left - 1, high = left;

    // Expand the window to find k closest elements
    while (k--)
    {
        if (low < 0 || (high < n && std::abs(nums[low] - x) > std::abs(nums[high] - x)))
        {
            high++;
        }
        else
        {
            low--;
        }
    }

    // Return the k closest elements
    return std::vector<int>(nums.begin() + low + 1, nums.begin() + high);
}

int main()
{
    std::vector<int> nums = {11, 22, 44, 56, 78, 99};
    int element = 56;
    int k = 3;

    std::vector<int> closestElements = findClosestElements(nums, k, element);

    std::cout << "Closest elements to " << element << ": ";
    for (int num : closestElements)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
