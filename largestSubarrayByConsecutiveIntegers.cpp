#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
	Given an array of integers,find largest length consecutive integers Sub-array

	1. Naive approach - is to check for every sub-array if it contains all consecutive integers
						then select the largest length sub-array
						Time complexity - O(N^3), Space complexity - O(1).
	2. Optimized approach - We can take advantage of the fact that numbers are consecutive,
							therefore we can maintain min and max in every window
							and if (max-min+1) == length of window,then we know for sure
							that this window contains consecutive integers
							Time Complexity - O(N^2), Space Complexity - O(1).
*/
class Solution
{
	vector<int> arr;
public:
	Solution()
	{

	}

	void fillArray(int temp)
	{
		arr.push_back(temp);
	}

	bool checkConsecutive(vector<int>& arr, int i, int j)
	{
		int min_element = INT_MAX;
		int max_element = INT_MIN;
		for (int idx = i; idx <= j; idx++)
		{
			min_element = min(min_element, arr[idx]);
			max_element = max(max_element, arr[idx]);
		}
		return (max_element - min_element) == (j - i) ;
	}

	int largestSubArray()
	{
		int maxLen = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			for (int j = i; j < arr.size(); j++)
			{
				if (checkConsecutive(arr, i, j))
				{
					maxLen = max(maxLen, j - i + 1);
				}
			}
		}
		return maxLen;
	}
};
int main()
{
	int test_case;
	cin >> test_case;
	while (test_case--)
	{
		Solution s;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			s.fillArray(temp);
		}
		cout << s.largestSubArray() << endl;
	}
}