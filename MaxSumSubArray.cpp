#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
	Find a subarray such that its sum is maximum

	Trivial approach :- 
	Find each and every subarray [i..j] and compute its sum
	get largest subarray whose sum is maximum
	TIme complexity - O(N^2),Space Complexity - O(1)
	
	Optimized approach :-
	suppose there is a subarray from [i..j]
	sum(i..j) = sum([i..k]) + sum([k+1..j])
	if sum(i..k) < 0 :
		then we can ignore the subarray from i..k
		as it will reduce our total sum of (i..j)
	Time complexity - O(N^2),Space complexity - O(1)
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
	pair<int,int> sumSubArray_trivial()
	{
		int largest_sum = INT_MIN;
		int st = -1;
		for(int i=0;i<arr.size();i++)
		{
			int sum = 0;
			for(int j=i;j<arr.size();j++)
			{
				sum += arr[j];
				if(sum > largest_sum)
				{
					largest_sum = sum;
					st = i;
				}
			}
		}
		return {largest_sum,st};
	}

	pair<int,int> sumSubArray()
	{
		int maxr = INT_MIN;
		for(auto it:arr)
		{
			maxr = max(maxr,it);
		}
		if(maxr < 0)
		{
			return maxr;
		}
		int sum = 0;
		int largest_sum = 0;
		int st = 0;
		for(int i=0;i<arr.size();i++)
		{
			sum += arr[i];
			if(sum < 0)
			{
				sum = arr[i];
				if(sum < 0)
				{
					sum = 0;
				}
				st = i;
			}
			if(sum > largest_sum)
			{
				largest_sum = sum;
				st = i;
			}
		}
		return largest_sum;
	}
};

int main()
{
	int test_cases;
	cin >> test_cases;
	while (test_cases--)
	{
		Solution s;
		int n;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			int temp ;
			cin >> temp;
			s.fillArray(temp);
		}
		auto it =  s.sumSubArray_trivial();
		cout << it.first << " " << it.second << endl;
	}
}




