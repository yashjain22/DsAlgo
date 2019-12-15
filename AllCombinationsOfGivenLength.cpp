#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
	The problem is to find all combinations of given length k

	Time complexity - O(N*(N-1)*(N-2).....(N-k+1))
*/
class Solution
{
	vector<int> arr;
public:
	Solution()
	{

	}
	void swap(int* x,int* y)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
	}
	void solve(int k,int n,vector<int>& nums,vector<vector<int>>& ans,vector<int>& currArray)
	{
		if(k == 0)
		{
			ans.push_back(currArray);
		}
		for(int i =0;i<n;i++)
		{
			currArray.push_back(nums[i]);
			if(n-1>=0)
			swap(&nums[i],&nums[n-1]);
			solve(k-1,n-1,nums,ans,currArray);
			if(currArray.size() >= 0)
			currArray.pop_back();
			if(n-1>=0)
			swap(&nums[i],&nums[n-1]);
		}
	}
	vector<vector<int>> findDistinctCombinations(int k)
	{
		vector<vector<int>> ans;
		vector<int> currArray;
		solve(k,arr.size(),arr,ans,currArray);
		return ans;
	}

	void fillArray(int temp)
	{
		arr.push_back(temp);
	}

	void printArray(vector<vector<int>> ans)
	{
		//cout << ans[1].size()<<endl;
		for(int i=0;i<ans.size();i++)
		{
			for(int j=0;j<ans[i].size();j++)
			{
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	int test_cases;
	cin >> test_cases;
	while (test_cases--)
	{
		Solution s;
		int k,n;
		cin >> k;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			int temp ;
			cin >> temp;
			s.fillArray(temp);
		}
		auto it = s.findDistinctCombinations(k);
		s.printArray(it);
	}
}




