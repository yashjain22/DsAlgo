#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/* 
trivial solution

optimized solution
Solution 1 :-
alwyays record the last occurence of zero,and increase the index
if again the zero is found at j,then your subarray would be prev_occurence

Solution 2 :-

Maintain a sliding window and this window would contain at most one zero,
if another zero is encountered,decrease the size of window until it is valid.
and at every expansion check if its the max Length.
Can also be generalized for at most k zeroes.
Try solving
Max consecutive ones iii - LeetCode 1004 
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

	int maxConsecutiveOnes_SlidingWindow(int k)
	{
		int i = 0;
		int j = 0;
		int maxLen = 0;
		int count = 0;
		while(i<=j && j<arr.size())
		{

			if(arr[j] == 0)
			{
				++count;
			}

			if(count > k)
			{

				while(i<=j)
				{
					if(arr[i] == 0)
					{
						--count;
					}
					++i;
					if(count <=k)
					{
						break;
					}
				}
			}
			maxLen = max(maxLen,j-i+1);
			++j;
		}
		return maxLen;
	}

	int maxConsecutiveOnes()
	{
		int prev_prev_zeroes = -1;
		int prev_zeroes = -1;
		int j = 0;
		int maxLen = 0;
		while(j < arr.size())
		{
			if(arr[j] == 0)
			{
				if(prev_prev_zeroes!= -1)
				{
					// prev_prev_zero+1...j-1
					maxLen = max(maxLen,(j-1-(prev_prev_zeroes+1)+1));
				}
				else
					if(prev_zeroes != -1)
				{
					// prev_zero ... j-1
					maxLen = max(maxLen,(j-prev_zeroes));
				}
				else
				{
					// j+1
					maxLen = max(maxLen,j+1);
				}
				prev_prev_zeroes = prev_zeroes;
				prev_zeroes = j;
			}
			else
			{
				if(prev_prev_zeroes != -1)
				{
					// prev_prev_zero+1..j
					maxLen = max(maxLen,j-prev_prev_zeroes);
				}
				else
					if(prev_zeroes != -1)
				{
					// j + 1
					maxLen = max(maxLen,j+1);
				}
				else
				{
					// j + 1
					maxLen = max(maxLen,j+1);
				}
			}
			++j;
		}
		return maxLen;
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
			int temp;
			cin >> temp;
			s.fillArray(temp);
		}
		cout << s.maxConsecutiveOnes_SlidingWindow(1) << endl;
	}
}

/*




*/