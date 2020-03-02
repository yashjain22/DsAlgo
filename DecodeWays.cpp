/*
	Given a string find the number of ways that it can be decoded

	for eg :- "112"
	can be decoded as (1,1,2) or (11,2) or (1,12)
	so only three ways are possible
	for eg:- "101"
	can only be decoded as (10,1)
	because "01" or "0" is not a valid string
*/
/*
	Lets discuss the top-down approach
	Cases :-
	1. 07 // leading zero
	2. 00 // multilpe zeroes
	3. 20 or 10 // trailing zero with valid string
	4. 40 // trailing zero with invalid string
	5. 11 to 26 // valid string
	6. 65 // valid string

	Lets handle all these cases One by one in our program
	and will try to build up the solution on that

	1. What would be our base case ?
		if we have completely exhausted the string then we sure know that it is a 
		valid string to be decoded.
	2.  Leading Zeroes cases
	3.  Trailing zero cases
	4. Valid string (two cases) a. >26 and <26
 */
#include<iostream>
#include<bits/stdc++.h>
using namepsace std;

class Solution {
    vector<int> dp;
public:
	int solve(string& s,int idx)
	{
		if(idx < 0) return 1;
		if(dp[idx] != -1) return dp[idx];
		if(idx - 1 < 0)
		{
			if(s[idx] >= '1' && s[idx] <= '9')
				return 1;
			else
				return 0;
		}
		if(s[idx-1] == '0') // all leading cases handled here
		{
			if(s[idx] == '0') return 0;
			return dp[idx] = solve(s,idx-1);
		}
		if(s[idx] == '0') // all trailing cases handled here
		{
			if(s[idx-1] == '1' || s[idx-1] == '2')
			{
				return dp[idx] = solve(s,idx-2);
			}
			else
			{
				return 0;
			}
		}
        
        string t = "";
        t += s[idx-1];
        t += s[idx];
        int num = stoi(t);
		if(num>=1 && num<=26)
		{
			return dp[idx] = solve(s,idx-1) + solve(s,idx-2);
		}
		else
		{
			return dp[idx] = solve(s,idx-1);
		}
	}
    int numDecodings(string s) {
        if(s.size() == 0)
        {
            return 0;
        }
        dp = vector<int>(s.size(),-1);
        return solve(s,s.size()-1);
    }
};