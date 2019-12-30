#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Leetcode 139 - very famous problem
you have been given a word and dictionary of words,we ave to tell whether we can use the words
in dictionary to form our given word,each word in the dictionary can be used multiple times.

My solution using DP

keep track of all indexes such that s[0...j] can be form using our word dictionary,
now at current index i,see whether for every j that can be formed using our dictionary,
whether s[j+1...i] exist in dictionary,if it exists than s[0...i] can be formed using the
dictionary.
Time complexity ->
pre-processing dictionary - O(N)
dictionary lookup time - O(1)
for building s[0...i], where i<=N - O(N^2)
O(N^2)
Space complexity ->
dictionary - O(N)
to keep track of indexes - O(N)   
O(N)
*/
class Solution
{
	set<string> unique_word;
	string word;
	vector<string> wordDict;
public:
	Solution(string word, vector<string> wordDict) {
		this->word = word;
		this->wordDict = wordDict;
	}
	bool solve_dp()
	{
		for (auto it : wordDict)
		{
			unique_word.insert(it);
		}
		bool dp[word.size() + 1];
		for (int i = 0; i <= word.size(); i++)
		{
			dp[i] = false;
		}
		dp[0] = true;

		for (int i = 0; i < word.size(); i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (dp[j] && unique_word.find(word.substr(j, i - j + 1)) != unique_word.end())
				{
					dp[i + 1] = true;
				}
			}
		}
		unique_word.clear();
		return dp[word.size()];
	}
};
int main()
{
	int test_cases;
	cin >> test_cases;
	int cnt = 0;
	while (test_cases--)
	{
		vector<string> wordDict;
		string word;
		cin >> word;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string word;
			cin >> word;
			wordDict.push_back(word);
		}
		Solution s(word,wordDict);
		++cnt;
		cout <<"Case #"<<cnt<<": "<< s.solve_dp() << endl;
	}
}