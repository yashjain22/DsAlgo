#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* the problem states that array contains 0, 1 and 2
   and we have to sort the array
   Naive approach - Sort using Count sort,where we can take count the occurences
   					of 0's, 1's and 2's.And based on the count we can sort.Also its
   					a stable sort algorithm,But it requires two traversal of arrays
   Optimized approach - we can only use three pointers,where we partition the array into
   three parts value less than pivot,value equal to pivot,value greater than pivot.
   arr[0..low] = 0's, arr[low+1..mid] = 1's, arr[mid+1..high] = 2's
   pivot would be equal to 1.
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

	void swap(int* x,int* y)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
	}

	void sortArray()
	{
		int low = -1;
		int mid = 0;
		int high = arr.size();
		while(mid < high)
		{
			if(arr[mid] == 0)
			{
				++low;
				swap(&arr[low],&arr[mid]);
				++mid;
			}
			else
				if(arr[mid] == 1)
			{
				++mid;
			}
			else
			{
				--high;
				swap(&arr[mid],&arr[high]);
			}
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

int main() {
	int test_cases;
	cin >> test_cases;
	while(test_cases--)
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
		s.sortArray();
		s.printArray();
	}
}