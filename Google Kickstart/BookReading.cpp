#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
	Google Kickstart BookReading Solution
	for Qi = 1 ,time complexity is O(1)
	and N > 1
	it would be N/x, x = Qi
	Since the sequence would be in a harmonic pattern N*(1/2+1/3+1/4 + ... + 1/N)
	in worst case time complexity would be O(N*logN + Q).
	since we are using two arrays first for storing our pages that are not torn out,
	second for storing the answers that have already been computed.
	Space complexity would be O(N). 
*/
class Solution
{
	bool arr[100006];
	vector<int> bookReader;
	int dp[100006];
	int n;
	int m;
public:
	Solution(int n, int m) {
		this->n = n;
		this->m = m;
	}
	void initialize()
	{
		for (int i = 1; i <= n; i++)
		{
			arr[i] = true;
		}
		for (int i = 1; i <= n; i++)
		{
			dp[i] = 0;
		}
	}
	void tornPage(int temp)
	{
		arr[temp] = false;
	}
	void fillBookReader(int temp)
	{
		bookReader.push_back(temp);
	}
	int bookReading(int x)
	{
		if (dp[x])
			return dp[x];
		if (x == 1)
		{
			return dp[x] = n - m;
		}
		int cnt = 0;
		for (int i = x; i <= n; i = i + x)
		{
			if (arr[i] == true)
			{
				++cnt;
			}
		}
		return dp[x] = cnt;
	}

};

int main()
{
	int test_cases;
	cin >> test_cases;
	int cnt = 0;
	while (test_cases--)
	{
		int n, m, q;
		cin >> n >> m >> q;
		Solution s(n, m);
		s.initialize();
		for (int i = 0; i < m; i++)
		{
			int temp;
			cin >> temp;
			s.tornPage(temp);
		}
		long long int sum = 0;
		for (int i = 0; i < q; i++)
		{
			int temp;
			cin >> temp;
			sum += s.bookReading(temp);
		}
		++cnt;
		cout << "Case #" << cnt << ": " << sum << endl;
	}
}