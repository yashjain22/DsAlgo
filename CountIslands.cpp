#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
 GIven a 2D array of 0s and 1s.Find number of islands,the island is defined
 as a group of 1s that are adjacent to each other.Code the most efficient possible solution.

 Most optimized approach ->
 Do BFS on each one in the binary matrix and keep track of visited element,since we are coding
 for most efficient possible solution,To keep track of visited elements we'll use another matrix
 just to track whether we have previously visited that element.
 
 !Now since BFS centrally expand from the centre point,crucially it is also important to note that number of
 elements can increase exponentially after every iteration in the worst case.So space will
 increase exponentially after every step.
 Overall the space/time complexity is O(n*m).
 We could also have solve this same problem with DFS. 
*/
class Solution
{
	bool visited[101][101];
	bool checkNeighbour(const vector<vector<int>>& binaryMatrix, int row, int col)
	{
		if (row >= binaryMatrix.size() || col >= binaryMatrix[0].size() || row < 0 || col < 0)
			return false;
		if (visited[row][col] == true || binaryMatrix[row][col] == 0)
			return false;
		visited[row][col] = true;
		return true;
	}
	void bfs(const vector<vector<int>>& binaryMatrix, int row, int col)
	{
		queue<pair<int, int>> q;
		visited[row][col] = true;
		q.push({row, col});
		while (!q.empty())
		{
			pair<int, int> front = q.front();
			q.pop();
			int x = front.first;
			int y = front.second;
			// checking its neighbours
			// (x,y) -> (x+1,y),(x-1,y),(x,y+1),(x,y-1)
			if (checkNeighbour(binaryMatrix, x + 1, y))
			{
				q.push({x + 1, y});
			}

			if (checkNeighbour(binaryMatrix, x - 1, y))
			{
				q.push({x - 1, y});
			}

			if (checkNeighbour(binaryMatrix, x, y + 1))
			{
				q.push({x, y + 1});
			}

			if (checkNeighbour(binaryMatrix, x, y - 1))
			{
				q.push({x, y - 1});
			}
		}
	}
	void initializeVisitedSet(const vector<vector<int>>& binaryMatrix)
	{
		for (int i = 0; i < binaryMatrix.size(); i++)
		{
			for (int j = 0; j < binaryMatrix[i].size(); j++)
			{
				visited[i][j] = false;
			}
		}
	}
public:
	Solution()
	{

	}
	int getNumberOfIslands( const vector<vector<int>>& binaryMatrix )
	{
		// your code goes here
		int num_islands = 0;
		if (binaryMatrix.size() == 0)
		{
			return 0;
		}
		initializeVisitedSet(binaryMatrix);

		for (int i = 0; i < binaryMatrix.size(); i++)
		{
			for (int j = 0; j < binaryMatrix[i].size(); j++)
			{
				if (visited[i][j] || binaryMatrix[i][j] == 0)
				{
					continue;
				}
				bfs(binaryMatrix, i, j);
				num_islands += 1;
			}
		}
		return num_islands;
	}
};

int main()
{
	int test_cases;
	cin >> test_cases;
	Solution s;
	while(test_cases--)
	{
		int row,col;
		cin >> row >> col;
		vector<vector<int> > binary_matrix;
		for(int i=0;i<row;i++)
		{
			vector<int> column;
			for(int j=0;j<col;j++)
			{
				int temp;
				cin >> temp;
				column.push_back(temp);
			}
			binary_matrix.push_back(column);
		}
		cout <<"Number of islands: " << s.getNumberOfIslands(binary_matrix) << endl;
	}
}