/*
    LeetCode 238 - Product of array except itself,without division operator
                   and without using any extra space except the ans array in
                   which we store te ans.
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    
        // left traversal
        int cur_product = 1;
        vector<int> output(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            output[i] = cur_product;
            cur_product *= nums[i];
        }
        cur_product = 1;
        // right traversal
        for(int i=nums.size()-1;i>=0;i--)
        {
            output[i] = output[i]*cur_product;
            cur_product *= nums[i];
        }
        
        return output;
    }
};