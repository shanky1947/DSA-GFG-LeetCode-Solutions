/*
https://leetcode.com/problems/combination-sum-ii/

40. Combination Sum II
Medium

3572

103

Add to List

Share
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

*/

//1st solution

class Solution {
public:
    void helper(vector<int> &A, int N, int B, int i, vector<vector<int>> &ans, vector<int> &so){
        if(B<0)
            return;
        if(B==0){
            sort(so.begin(), so.end());
            for(int k:so)
                cout<<k;
            cout<<endl;
            if(find(ans.begin(), ans.end(), so)==ans.end())
                ans.push_back(so);
            return;
        }     
        if(i>=N)
            return;
        so.push_back(A[i]);
        helper(A, N, B-A[i], i+1, ans, so);
        so.pop_back();
        helper(A, N, B, i+1, ans, so);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> so;
        sort(candidates.begin(), candidates.end());
        helper(candidates, candidates.size(), target, 0, ans, so);
        // sort(ans.begin())
        return ans;
    }
};


//2nd solution

class Solution {
public:
    void combination(vector<int>& candidates, int target, vector<int> curr, vector<vector<int>>& result, int idx) {
        if(target < 0)
            return;
        if(target == 0) {
            result.push_back(curr);
            return;
        }
        
        for(int i = idx; i<candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1])
                continue; //ignore duplicate elements
            curr.push_back(candidates[i]);
            combination(candidates, target-candidates[i], curr, result, i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end()); //because we will ignore duplicate elements
        combination(candidates, target, curr, result, 0);
        return result;
    }
};
