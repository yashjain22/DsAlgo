/*
Leetcode 3 Longest Substring Without Repeating Characters

Approach ->
// take two pointer left and right 
// maintain a char set,see if the char at right pointer has ever been seen before,
// if it is seen decrease the window size by first removing from set then increasing left pointer 
// otherwise expand the window size by increasing right pointer and also recording the length of window
// Check if current window length is greater than maxLen,then assign maxLen = currLen.

Time complexity ->
O(N)
Space complexity ->
O(M) = O(C),M are unique chars
,because atmost there can be only 26 unique characters
therefore space complexity is constant.
*/
class Solution {
    unordered_set<char> s;
public:
    int lengthOfLongestSubstring(string word) {
        if(word.size() == 0)
        {
            return 0;
        }
        int i=0;
        int j=0;
        int maxLen = 0;
        while(j<word.size())
        {
            if(s.find(word[j])!=s.end())
            {
                while(s.find(word[j]) != s.end()&&i<=j)
                {
                    s.erase(s.find(word[i]));
                    ++i;
                }
            }
            s.insert(word[j]);
            maxLen = max(maxLen,j-i+1);
            ++j;
        }
        return maxLen;
    }
};