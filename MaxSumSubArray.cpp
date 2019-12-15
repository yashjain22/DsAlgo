#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
	Find a subarray such that its sum is maximum

	Trivial approach :- 
	Find each and every subarray [i..j] and compute its sum
	get largest subarray whose sum is maximum
	

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




