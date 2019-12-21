#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
	Question ->
	Given a sorted array "arr" of distinct integers,  write a function 
	that returns the lowest index i for which arr[i] == i.Return -1 if there is no such
	index.
	
	Trivial solution ->
	Just do a simple linear search

	Optimized solution ->
	Many people were able to figure out that binary-search would work,
	but they failed to give the solid proofs when asked on why binary search would
	always work in this case.Even the interviewer who asked the question was not prepared
	with the solid proof.

	To understand when did exactly B.S. (short notation for binary search) works
	when array is sorted (right), Can we go more deeper than this
	can somehow explain it mathematically
	so here we go,
	B.S. works exactly
	when for every x > y , f(x) >= f(y) or vice versa
	So see our array is sorted and we are given the task of finding
	arr[i] == i for some i
	lets denote our array as -> f(x), x->index
	lets denote our index as -> h(x), x->index,
	h(x) = x
	So our diff function would look something like this -> g(x) = f(x) - h(x)
	and if we can prove g(x) >= g(y) for every x > y.
	Then our condition for B.S. would suffice.
	
	so take an example,
	g(x+1) = f(x+1) - h(x+1)
	g(x+1) = f(x+1) - h(x) - 1
	g(x+1) = f(x+1)-f(x) -1 + g(x)
	f(x+1)-f(x)-1 >= 0,because array is distinct and it contains only integer numbers
	,therefore f(x+1) >= f(x) + 1
	so,we proved that
	g(x+1) >= g(x),

*/
class Solution
{
private:
vector<int> arr;
int binary_search(int low,int high)
{
	int cur_ans = -1;
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		if(arr[mid] - mid < 0)
		{
			low = mid + 1;
		}
		else
			if(arr[mid] - mid >= 0)
		{
			if(arr[mid] == mid)
			{
				cur_ans = mid;
			}
			high = mid - 1;
		}
	}
	return cur_ans;
}
public:
	void fillArray(int temp)
	{
		arr.push_back(temp);
	}

	int findIndexEuality()
	{
		return binary_search(0,arr.size()-1);
	}
	void cleanArray()
	{
		arr.clear();
	}
};
int main()
{
	int test_cases;
	cin >> test_cases;
	Solution s;
	while(test_cases--)
	{
		int n;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin >> temp;
			s.fillArray(temp);
		}
		int ans = s.findIndexEuality();
		cout << ans << " " << endl;
		s.cleanArray();
	}
}