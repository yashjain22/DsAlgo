#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
	Given an array of integers,rearrange the array in such a way that every
	odd-indexed element is greater than its neighbours and every even indexed
	element is smaller than its neighbours
	Initial Approach -
	a. Sort the array in ascending order
	b. take two pointers one at i=0 and other at j = arr.size()-1
	   increment i and decrement j
	c. Take an auxiliary array and store in it the value of pointers 
	   indexed at array i and j
	
	Optimized approach -
	a. Sort the array in ascending order
	b. int i = 2
	c. while(i<size)
	d. {swap(arr[i],arr[i-1])
	e.  i = i + 2
		}
	[1,2,3,4,5,6,7]
	first swap  - 1,3,2,4,5,6,7
	second swap - 1,3,2,5,4,6,7
	third swap - 1,3,2,5,4,7,6
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

	void alternateLowHigh()
	{
		sort(arr.begin(),arr.end());
		int i = 2;
		while(i < arr.size())
		{
			swap(&arr[i],&arr[i-1]);
			i += 2;
		}
	}

	void swap(int* x,int* y)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
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
// [3,6,7,8,9]
// 3,7,6,9,8
int main()
{
	int test_cases;
	cin >> test_cases;
	while (test_cases--)
	{
		Solution s;
		int n;
		cin >> n;
		for(int i = 0 ;i<n;i++)
		{
			int temp ;
			cin >> temp;
			s.fillArray(temp);
		}
		s.alternateLowHigh();
		s.printArray();
	}
}

/*
	Test cases

	input :-

	



*/




