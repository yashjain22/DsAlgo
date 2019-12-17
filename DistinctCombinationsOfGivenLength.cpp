#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
All distinct combinations of given length k



*/
class Solution
{
	vector<int> arr;
public:
	Solution()
	{

	}

	void solveWithRepetition(int k,int i,vector<int>& arr,vector<int>& temp,vector<vector<int>>& ans)
	{
		if( k == 0)
		{
			ans.push_back(temp);
			return;
		}

		for(int j=i;j<arr.size();j++)
		{
			temp.push_back(arr[j]);
			solveWithRepetition(k-1,j,arr,temp,ans);
			temp.pop_back();
		}
	}

	void solveWithoutRepetition(int k,int i,vector<int>& arr,vector<int>& temp,vector<vector<int>>& ans)
	{
		if(k == 0)
		{
			ans.push_back(temp);
			return;
		}

		for(int j=i+1;j<arr.size();j++)
		{
			temp.push_back(arr[j]);
			solveWithoutRepetition(k-1,j,arr,temp,ans);
			temp.pop_back();
		}
	}

	vector<vector<int>> findDistinctCombinationWithoutRepetition(int k)
	{
		sort(arr.begin(),arr.end());
		vector<vector<int>> ans;
		vector<int> temp;
		solveWithoutRepetition(k,-1,arr,temp,ans);
		return ans;
	}

	vector<vector<int>> findDistinctCombinationWithRepetition(int k)
	{
		sort(arr.begin(),arr.end());
		vector<vector<int>> ans;
		vector<int> temp;
		solveWithRepetition(k,0,arr,temp,ans);
		return ans;
	}

	void fillArray(int temp)
	{
		arr.push_back(temp);
	}

	void printAllCombinations(vector<vector<int>> ans)
	{
		for(int i=0;i<ans.size();i++)
		{
			for(int j=0;j<ans[i].size();j++)
			{
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	int test_cases;
	cin >> test_cases;
	while (test_cases--)
	{
		Solution s;
		int n,k;
		cin >> n >> k;
		for(int i=0;i<n;i++)
		{
			int temp ;
			cin >> temp;
			s.fillArray(temp);
		}
		cout << "Distinct combinations without repetition" << endl;
		vector<vector<int> > ans1 = s.findDistinctCombinationWithoutRepetition(k);
		s.printAllCombinations(ans1);
		cout << "----------------------------------------" << endl;
		cout <<  "Distinct combinations with repetition" << endl;
		vector<vector<int> > ans2 = s.findDistinctCombinationWithRepetition(k);
		s.printAllCombinations(ans2);
	}
}