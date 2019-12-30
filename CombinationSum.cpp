/*
    LeetCode 39 - Combination Sum,given a target and a candidate set
    find all unique combinaion in candidate set that sums to target.
    each number in candidate set could be used multiple times.
*/

class Solution {
    vector<vector<int>> ans;
public:
    void solve(vector<int>& candidates, int curr_sum, int idx, vector<int>& temp)
    {
        if (curr_sum < 0)return;
        if (curr_sum == 0)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < candidates.size(); i++)
        {
            temp.push_back(candidates[i]);
            solve(candidates, curr_sum - candidates[i], i, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates, target, 0, temp);
        return ans;
    }
};