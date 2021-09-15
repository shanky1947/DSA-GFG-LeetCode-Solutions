/*
https://leetcode.com/problems/palindrome-partitioning/

131. Palindrome Partitioning
Medium

4466

136

Add to List

Share
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.

*/


class Solution {
public:
    bool isPalindrome(string s){
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    void helper(vector<vector<string>>& ans, vector<string> so, string s){
        int n=s.size();
        if(n<=0){
            ans.push_back(so);
            return;
        }    
        for(int i=1;i<=n;i++){
            string s1=s.substr(0, i);
            if(isPalindrome(s1)){
                so.push_back(s1);
                helper(ans, so, s.substr(i, n-i));
                so.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> so;
        helper(ans, so, s);
        return ans;
    }
};
