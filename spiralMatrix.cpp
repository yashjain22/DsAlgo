#include<iostream>
#include<vector>
using namespace std;
/*
 Was asked in an actual interview,and the below solution is exactly as i coded in the interview.
 It has been assumed that input matrix is given to you
 constraints (row>=1&&row<=100) and (column>=1&&column<=100)
 Interview was over after 40 minutes.
 and the approach i explained in that interview as :-
 do four traversal in one iteration
 left -> right
 top -> bottom 
 right -> left
 bottom -> top
 after every traversal adjust the bounds.
 left -> right (top = top +1)
 top -> bottom (right = right - 1)
 right -> left (bottom = bottom - 1)
 bottom -> top (left = left + 1)
 and stop the iteration whenever any of the bounds fails to verify.
*/
class Solution
{

	void horizontalTraversal(const vector<vector<int>>& inputMatrix, int left, int right, int top, vector<int>& ans)
	{
		for (int i = left; i <= right; i++)
		{
			ans.push_back(inputMatrix[top][i]);
		}
	}

	void inverthorizontalTraversal(const vector<vector<int>>& inputMatrix, int right, int left, int bottom, vector<int>& ans)
	{
		for (int i = right; i >= left; i--)
		{
			ans.push_back(inputMatrix[bottom][i]);
		}
	}

	void verticalTraversal(const vector<vector<int>>& inputMatrix, int top, int bottom, int right, vector<int>& ans)
	{
		for (int i = top; i <= bottom; i++)
		{
			ans.push_back(inputMatrix[i][right]);
		}
	}

	void invertverticalTraversal(const vector<vector<int>>& inputMatrix, int bottom, int top, int left, vector<int>& ans)
	{
		for (int i = bottom; i >= top; i--)
		{
			ans.push_back(inputMatrix[i][left]);
		}
	}
public:
	void printAns(vector<int>& arr)
	{
		for(auto it:arr)
		{
			cout << it << " ";
		}
		cout << endl;
	}
	vector<int> spiralCopy( vector<vector<int>>& inputMatrix )
	{
		int n = inputMatrix.size();
		int m = inputMatrix[0].size();
		int left = 0;
		int right = inputMatrix[0].size() - 1;
		int top = 0;
		int bottom = inputMatrix.size() - 1;
		vector<int> ans;

		while (left <= right && top <= bottom)
		{
			if (top >= n || right < 0 || left >= m)
			{
				continue;
			}
			horizontalTraversal(inputMatrix, left, right, top, ans);
			top = top + 1;

			if (right < 0 || top >= n || bottom < 0)
			{
				continue;
			}
			verticalTraversal(inputMatrix, top, bottom, right, ans);
			right = right - 1;


			if (bottom < 0 || right < 0 || left >= m)
			{
				continue;
			}
			inverthorizontalTraversal(inputMatrix, right, left, bottom, ans);
			bottom = bottom - 1;


			if (left >= m || bottom < 0 || top >= n)
			{
				continue;
			}
			invertverticalTraversal(inputMatrix, bottom, top, left, ans);
			left = left + 1;
		}
		return ans;
		//return
	}
};


int main()
{

}