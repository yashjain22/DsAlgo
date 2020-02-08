#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Two possible solutions ->
1. first one requires extra memory but does the job in linear time.(Time-efficient)
2. second one requires more time at the expense of memory.(Memory-efficient)
   inplace ordered.
*/
class Solution
{
	vector<int> arr;
	int len;
public:
	Solution() {this->len = 0;}
	void fillArray(int val)
	{
		arr.push_back(val);
	}
	void printArray(int len)
	{
		for (int i=0;i<len;i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void firstSolution()
	{
		unordered_set<int> s;
		for (auto it : arr)
		{
			if (s.find(it) == s.end())
			{
				s.insert(it);
			}
		}
		arr.clear();
		for (auto it = s.begin(); it != s.end(); it++)
		{
			arr.push_back(*it);
		}
	}
	int secondSolution()
	{
		// inplace remove duplicates in array
		// 4 0 5 0 6 0
		// sort the array to ---> 0 0 0 4 5 6
		// take two pointers i and j
		// skip till you find the same element
		// if elements are different then change the window size.
		std::sort(arr.begin(), arr.end());
		int i = 0;
		int j = 0;
		int pos = 0;
		while (i <= j && j < arr.size())
		{
			if (arr[i] == arr[j])
			{
				++j;
				continue;
			}
			else
			{
				i = j;
				arr[++pos] = arr[i];
			}
		}
		return pos+1;
	}
};


int main()
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
	int len = s.secondSolution();
	s.printArray(len);
}
