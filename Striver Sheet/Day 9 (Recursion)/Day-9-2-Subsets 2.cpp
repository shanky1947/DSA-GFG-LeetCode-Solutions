/*
https://leetcode.com/problems/subsets-ii/

90. Subsets II
Medium

3464

124

Add to List

Share
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10


*/

class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int> so, int i){
        if(i==nums.size()){
            if(find(ans.begin(), ans.end(), so)==ans.end())
                ans.push_back(so);
            return;
        }
        helper(nums, ans, so, i+1);
        so.push_back(nums[i]);
        helper(nums, ans, so, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> so;
        helper(nums, ans, so, 0);
        return ans;
    }
};
