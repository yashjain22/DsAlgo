/*
LeetCode 64 - Min Path sum
dp[i][j] = min(dp[i][j-1],dp[i-1][j])
*/
class Solution {
    int dp[1001][1001];
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                dp[i][j] = INT_MAX;
            }
        }
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                int sum = grid[i][j];
                int minr = INT_MAX;
                if (j - 1 >= 0)
                {
                    minr = min(minr, dp[i][j - 1]);
                }
                if (i - 1 >= 0)
                {
                    minr = min(minr, dp[i - 1][j]);
                }
                if (minr != INT_MAX)
                {
                    sum += minr;
                }
                dp[i][j] = sum;
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};
