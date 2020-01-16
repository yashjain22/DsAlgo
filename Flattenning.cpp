#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Google kickstart Round-F 2019 Problem A FLattening solution By DP
*/

/*
Problem resolves to making =<K equal subarrays
with min cost
Thinkin of DP solution
cost of making n=1 0
n = 2, cost = 0
n = k, cost = 0
n = k + 1 ,

300 100 300 300 200 100 800 500      2

[0,0],[1,1],[2,3],[4,4],[5,5],[6,6],[7,7]
[0,3] [4,4] [5,5] [6,6] [7,7]  - 1
[0,4] [5,5] [6,6] [7,7] - 2
[0,5] [6,6] [7,7] - 3

300 300 300 300 300 300 800 500

find the solution for k = 1
then k = 2

T(i..j,K) = min(T[i...y,K-1] + R[y...j])
where R is the function of the cost for making all elements equal in that range.

This solution passes both the test cases (set-1 and set-2)
And the time - complexity is --> O(N^3*K)
where 1=<N<=100 and K<=N.
*/
int dp[101][101][101];
int lp[101][101];
class Solution
{
	int n, k;
	vector<int> arr;
	// dp[i][j][k]
public:
	Solution(int n, int k) {
		this -> n = n;
		this -> k = k;
	}
	void fillArray(int temp)
	{
		arr.push_back(temp);
	}
	void printArray()
	{
		for (int x : arr)
		{
			cout << x << " ";
		}
		cout << endl;
	}

	int find_ans(int low, int high)
	{
		if (low == high)
		{
			return 0;
		}
		int cnt = 0;
		unordered_map<int,int> m;
		m.clear();
		for (int i = low; i <= high; i++)
		{
			m[arr[i]]++;
		}
		for(auto it:m)
		{
			cnt = max(cnt,it.second);
		}
		return high-low+1-cnt;
	}

	int solve()
	{
		for (int i = 0; i < arr.size(); i++)
		{
			for (int j = i; j < arr.size(); j++)
			{
				dp[i][j][0] = find_ans(i, j);
				lp[i][j] = dp[i][j][0];
			}
		}
		for (int t = 1; t <= k; t++)
		{
			for (int i = 0; i < arr.size(); i++)
			{
				for (int j = i+1; j < arr.size(); j++)
				{
						dp[i][j][t] = INT_MAX;
					for (int x = i; x < j; x++)
					{
						dp[i][j][t] = min(dp[i][j][t], dp[i][x][t - 1] + lp[x+1][j]);
					}
				}
			}
		}
		return dp[0][arr.size() - 1][k];
	}
};
int main()
{
	int test_cases;
	cin >> test_cases;
	int cnt = 1;
	while (test_cases--)
	{
		int n, k;
		cin >> n >> k;
		Solution s(n, k);
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			s.fillArray(temp);
		}
		//s.printArray();
		cout << "Case #" << cnt << ": " << s.solve() << endl;
		++cnt;
	}
}