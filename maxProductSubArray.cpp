
/*
    Used divide and conquer approach to solve this problem,
    not the most optimal solution
    Time complexity - O(N*LogN), each merging part tooks O(N) times the height
                      of tree.
    Space complexity - O(Logn) or O(h) - the height of recursion tree.
*/

class Solution {
    int solve(int low,int high,vector<int>& nums)
    {
        if(low > high)
        {
            return 1;
        }
        if(low == high)
        {
            return nums[low];
        }
        int mid = low + (high-low)/2;
        int left_prod = solve(low,mid,nums);
        int right_prod = solve(mid+1,high,nums);
        int prod = 1;
        // j = mid ---> high
        // i = mid - 1 ---> low
        int minr1 = 0;
        int maxr1 = 0;
        for(int j = mid;j<=high;j++)
        {
            prod = prod * nums[j];
            minr1 = min(prod,minr1);
            maxr1 = max(prod,maxr1);
        }
        prod = 1;
        int minr2 = 0;
        int maxr2 = 0;
        for(int i = mid-1;i>=0;i--)
        {
            prod = prod * nums[i];
            minr2 = min(minr2,prod);
            maxr2 = max(maxr2,prod);
        }
        prod = max(max(maxr1,maxr2),max(minr1*minr2,maxr1*maxr2));
        return max(max(left_prod,right_prod),prod);
    }
public:

    int maxProduct(vector<int>& nums) {
        return solve(0,nums.size()-1,nums); 
    }
};