/*
392. Is Subsequence

Given a string s and a string t, check if s is subsequence of t.
You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and sis a short string (<=100).
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
Example 1:
s = "abc", t = "ahbgdc"
Return true.
Example 2:
s = "axc", t = "ahbgdc"
Return false.
Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

From <https://leetcode.com/problems/is-subsequence/description/>
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;

        for(int i = 0; i < t.length() && index < s.length(); i++) {
            if(t[i] == s[index]) {
                index++;
            }
        }

        return index == s.length();
    }
};

