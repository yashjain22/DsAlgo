#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Approach - sort the intervals by their starting points so that upto
[0...x],where x>=0 has no overlapping interval and the next interval could
either be overlap,partially-overlap or totally Non-overlapping.
Time complexity - O(N), SpaceComplexity - O(N)
*/
bool comparator(pair<int,int> first_interval,pair<int,int> second_interval)
{
    return first_interval.first == second_interval.first ? first_interval.second < second_interval.second : first_interval.first < second_interval.first;
}
class Solution
{
vector<pair<int,int>> arr;
public:
  Solution()
  {}

  void fillArray(pair<int,int> interval)
  {
    arr.push_back(interval);
  }

  vector<pair<int,int>> mergeIntervals()
  {
    sort(arr.begin(),arr.end(),comparator);
    vector<pair<int,int>> ans;
    if(arr.size() >= 1)
    {
      ans.push_back(arr[0]);
    }
    if(arr.size() <= 1)
    {
      return ans;
    }
    for(int i=1;i<arr.size();i++)
    {
      int left = ans[ans.size() -1 ].first;
      int right = ans[ans.size() - 1].second;
      // overlapping case
      if(arr[i].first >= left && arr[i].second <= right)
      {
        continue;
      }
      if(arr[i].second > right)
      {
        // partially overlapping case
        if(arr[i].first>=left && arr[i].first<=right)
        {
          ans.pop_back();
          ans.push_back({left,arr[i].second});
        }
        else  // Non-overlapping case
        {
          ans.push_back({arr[i].first,arr[i].second});
        }
      }
    }
    return ans;
  }

  void printArray(vector<pair<int,int> >& ans)
  {
    for(int i=0;i<ans.size();i++)
    {
      cout << "(" << ans[i].first << " " << ans[i].second << ")"<<endl;
    }
  }
};

int main()
{
  int test_cases;
  cin >> test_cases;
  while(test_cases --)
  {
    Solution s;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
      int left,right;
      cin >> left >> right;
      s.fillArray({left,right});
    }
    vector<pair<int,int>> ans = s.mergeIntervals();
    s.printArray(ans);
  }
}
