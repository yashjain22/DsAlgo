#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
 Problem reference LeetCode - 969
 if we can somehow place max(0..n) at n
 so the problem resolves to max(0..n-1) at n-1
 so on
 Until the whole array would become sorted.
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

	void swap(int* x, int* y)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
	}

	void flipOperation(int k)
	{
		int i = 0;
		int j = 0 + k - 1;
		while (i < j)
		{
			swap(&arr[i], &arr[j]);
			++i;
			--j;
		}
	}

	int findMaxIndex(int high)
	{
		int maxr = INT_MIN;
		int max_index = -1;
		for (int i = 0; i <= high; i++)
		{
			if (arr[i] > maxr)
			{
				maxr = arr[i];
				max_index = i;
			}
		}
		return max_index;
	}

	vector<int> pancakeSort()
	{
		int n = arr.size() - 1;
		while (n >= 0)
		{
			int idx = findMaxIndex(n);
			flipOperation(idx + 1);
			flipOperation(n + 1);
			n--;
		}
	}

	void printArray()
	{
		for(auto it:arr)
		{
			cout << it << " ";
		}
		cout << endl;
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
		s.pancakeSort();
		s.printArray();
	}
}




