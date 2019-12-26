#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*
 0 1 1
	6/2 = 3/2 = 1 /2 = 0
*/
class Solution
{
	int binary_array[1006][60];
	ll int n;
	ll int m;
public:
	Solution(ll int n, ll int m) {
		this -> n = n;
		this -> m = m;
	}
	vector<int> convertToBinary(ll int num)
	{
		vector<int> arr;
		while (num > 0)
		{
			arr.push_back(num % 2);
			num = num / 2;
		}
		//printArray(arr);
		return arr;
	}
	void initialize()
	{
		for (ll int i = 0; i < n; i++)
		{
			for (ll int j = 0; j < 60; j++)
			{
				binary_array[i][j] = 0;
			}
		}
	}
	void getInput(int i, ll int num)
	{
		vector<int> arr = convertToBinary(num);

		for (int j = 0; j < arr.size(); j++)
		{
			binary_array[i][j] = arr[j];
		}
	}
	void printArray(vector<ll int>& arr)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	pair<int, bitset<64>> solve()
	{
		unsigned ll int min_sum[61];
		for (int i = 0; i <= 60; i++)
		{
			min_sum[i] = 0;
		}

		for (int j = 0; j < 59; j++)
		{
			int count_zero = 0;
			int count_ones = 0;
			for (int i = 0; i < n; i++)
			{
				if (binary_array[i][j])
				{
					++count_ones;
				}
				else
				{
					++count_zero;
				}
			}
			min_sum[j + 1] = min_sum[j] + pow(2, j) * min(count_ones, count_zero);
		}

		bitset<64> k(0);
		for (int j = 59; j >= 0; j--)
		{
			int count_zero = 0;
			int count_ones = 0;
			for (int i = 0; i < n; i++)
			{
				if (binary_array[i][j])
				{
					++count_ones;
				}
				else
				{
					++count_zero;
				}
			}
			if (count_zero <= count_ones)
			{
				//ans += pow(2, j);
				k.set(j);
				m -= pow(2, j) * count_zero;
				if (m < 0)
				{
					return { -1, k};
				}
			}
			else
			{
				if (m - pow(2, j)*count_zero >= min_sum[j])
				{
					m -= pow(2, j) * count_zero;
					//ans += pow(2, j);
					k.set(j);
				}
				else
				{
					m -= pow(2, j) * count_ones;
					if (m < 0)
					{
						return { -1, k};
					}
				}
			}
		}
		if (m < 0)
		{
			return { -1, k};
		}
		return {0, k};
	}

};

int main()
{
	int test_cases;
	cin >> test_cases;
	int cnt = 0;
	while (test_cases--)
	{
		ll int n, m;
		cin >> n >> m;
		Solution s(n, m);
		s.initialize();
		for (int i = 0; i < n; i++)
		{
			ll int temp;
			cin >> temp;
			s.getInput(i, temp);
		}
		++cnt;
		pair<int, bitset<64>> ans = s.solve();
		if (ans.first == -1)
		{
			cout << "Case #" << cnt << ": " << -1 << endl;
		}
		else
		{
			cout << "Case #" << cnt << ": " << ans.second.to_ullong() << endl;	
		}
	}
}