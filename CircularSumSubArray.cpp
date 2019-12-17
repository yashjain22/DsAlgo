#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
	Optimized approach :-
	To find the max sum in a circular subArray
	approach 1 - one can find the minsubarray sum and subtract it from the whole subarray
				minSubarraysum can easily be found by A[i] -> -A[i],
				and finding max using kadane algorithm.
	Time complexity - O(n),Space complexity - O(1)
	Requires two traversal of arrays

	approach 2 - One can always divide the array into three parts,
				 first part -> 0<=i<=j<=n-1
				 second part -> i=0..k<=n-1
				 third part -> 0<i..j=n-1
				 then finding max as max(first_part,second_part+third_part).
	Time complexity - O(n),Space complexity - O(1)
	Also requires two traversal of arrays
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

	int findMax()
	{
		int maxr = INT_MIN;
		for (auto it : arr)
		{
			maxr = max(maxr, it);
		}
		return maxr;
	}

	int findMaxSubArraySum()
	{
		int sum = 0;
		int largest_sum = 0;
		for (auto it : arr)
		{
			sum += it;
			if (sum < 0)
			{
				if (it < 0)
				{
					sum = 0;
				}
				else
				{
					sum  = it;
				}
			}
			largest_sum = max(largest_sum, sum);
		}
		return largest_sum;
	}

	void invertArray()
	{
		for (int i = 0; i < arr.size(); i++)
		{
			arr[i] = -1 * arr[i];
		}
	}

	int findTotalSum()
	{
		int sum = 0;
		for (auto it : arr)
		{
			sum += it;
		}
		return sum;
	}

	int maxCircularSum()
	{
		int largest_sum = 0;
		int largest_sum_kadane = findMax();
		if (largest_sum_kadane < 0)
		{
			return largest_sum_kadane;
		}
		largest_sum_kadane = findMaxSubArraySum();
		int total_sum = findTotalSum();
		invertArray();
		int largest_inverted_sum = findMaxSubArraySum();
		// largest_sum = -minSubArray
		//cout << total_sum << " " << largest_sum << endl;
		return max(largest_sum_kadane, total_sum + largest_inverted_sum);
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
		for (int i = 0; i < n; i++)
		{
			int temp ;
			cin >> temp;
			s.fillArray(temp);
		}
		cout << s.maxCircularSum() << endl;
	}
}