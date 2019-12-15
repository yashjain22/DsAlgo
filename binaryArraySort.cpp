#include<iostream>
#include<vector>
using namespace std;
/*
 Naive approch is to stable_sort using any sorting algorithm
 More optimized approach is to take advantage that only 0,1 is present in array
 We can choose 0 as a pivot and then seggregate 0's to one side,which will result in
 all 1's to other side,Therefore our array will become sorted
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

	void sortArray()
	{
		int j = -1;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] == 0)
			{
				++j;
				swap(&arr[i], &arr[j]);
			}
		}
	}

	void printArray()
	{
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	int test_case;
	cin >> test_case;
	while (test_case--)
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
		s.sortArray();
		s.printArray();
	}

}
