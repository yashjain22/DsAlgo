#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Google kickstart Round A sliding window solution
Time complexity - O(N)
*/
class Solution
{
    vector<int> arr;
    int n;
    int p;
  public:
  Solution(int n,int p) {
      this -> n = n;
      this -> p = p;
  };
  void fillArray(int temp)
  {
    arr.push_back(temp);
  }
  int find_ans(int low,int high)
  {
      int ele = arr[high];
      int cnt = 0;
      for(int i=low;i<=high;i++)
      {
        cnt = cnt + (ele-arr[i]);  
      }
      return cnt;
  }
  int solve()
  {
    sort(arr.begin(),arr.end());
    int ele = arr[p-1];
    int sum = 0;
    int cnt = 0;
    for(int i=0;i<p;i++)
    {
        sum += arr[i];
    }
    cnt = p*ele - sum;
    
    for(int i=0;i<n-p;i++)
    {
        sum -= arr[i];
        sum += arr[i+p];
        cnt = min(cnt,p*arr[i+p]-sum);
    }
    return cnt;
  }
};
int main()
{
    int test_cases;
    cin >> test_cases;
    int cnt = 1;
    while(test_cases--)
    {
        int n,p;
        cin >> n >> p;
        Solution s(n,p);
        for(int i=0;i<n;i++)
        {
            int temp;
            cin >> temp;
            s.fillArray(temp);
        }
        cout <<"Case #"<<cnt<<": "<<s.solve() << endl;
        ++cnt;
    }
}
