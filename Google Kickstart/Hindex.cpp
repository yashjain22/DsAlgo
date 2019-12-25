#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
	Google kickstart round-H   (H-Index) Solution
	Used priority queue to keep track of H-index and whenever the size of queue is greater than h-index,
	then there probably is better h-index is possible so increase h-index and remove all elements smaller
	than h-index.
	Time complexity - O(N*logN),N - number of elements
	Space complexity - O(N)
	This is enough to pass all test cases (set-1 and set-2).
*/
class Solution
{
	vector<int> arr;
	multiset<int> s;
public:
	Solution() {}
	void fillArray(int temp)
	{
		arr.push_back(temp);
	}
	vector<int> findHindex()
	{
		int h_index = 0;
		vector<int> ans;
		for (int i = 0; i < arr.size(); i++)
		{
			// add element
			if (arr[i] > h_index)
			{
				s.insert(arr[i]);
			}
			// empty set
			if (s.size() == 0)
			{
				ans.push_back(h_index);
				continue;
			}
			// update h-index,do book-keeping work
			do
			{
				auto it  = s.begin();   // 1
				int len = s.size();    // 2
				h_index = max(h_index, min(*it, len)); // 1
				while (s.size() > 0 && *it <= h_index) // 1 <= 1
				{
					s.erase(it); // 3
					if (s.size() > 0) // 1
						it = s.begin(); // 3
				}
				if (s.size() > *s.begin())      // 1
				{
					s.erase(s.begin());
				}
			} while (s.size() > 0 && s.size() > *s.begin());
			ans.push_back(h_index);
		}
		return ans;
	}
};

void printArray(vector<int>& ans, int cnt)
{
	cout << "Case #" << cnt << ": ";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}
int main()
{
	int test_cases;
	cin >> test_cases;
	int cnt = 0;
	while (test_cases--)
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
		vector<int> ans = s.findHindex();
		++cnt;
		printArray(ans, cnt);
	}
}