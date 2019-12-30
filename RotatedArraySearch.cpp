/*
Leetcode 33 - A sorted array has been rotated by an unknown offset,given a value
             search in this rotated array.If value is found return the index,
             else return -1.

Time complexity - O(LogN)
Space complexity - O(1)
*/
class Solution {
public:
    int binary_search(vector<int>& nums, int target, int low, int high)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }

    int findBreakingPoint(vector<int>& nums, int low, int high)
    {
        if (low == high) return low;
        int mid = low + (high - low) / 2;
        if (mid == 0 || mid == nums.size() - 1)
        {
            return mid;
        }
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        {
            return mid;
        }

        if (nums[low] < nums[mid])
        {
            return findBreakingPoint(nums, mid + 1, high);
        }
        else
        {
            return findBreakingPoint(nums, low, mid);
        }
    }
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        int breaking_point = findBreakingPoint(nums, 0, nums.size() - 1);
        int l_index = binary_search(nums, target, 0, breaking_point);
        int r_index = binary_search(nums, target, breaking_point + 1, nums.size() - 1);
        return max(l_index, r_index);
    }
};