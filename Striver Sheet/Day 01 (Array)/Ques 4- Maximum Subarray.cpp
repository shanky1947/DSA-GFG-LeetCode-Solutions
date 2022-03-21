/*
Q Link- https://leetcode.com/problems/maximum-subarray/

53. Maximum Subarray
Easy

19218

923

Add to List

Share
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Accepted
2,176,816
Submissions
4,401,754
*/


//FIND 1 VALUE-> GIVEN ROW NO., COL NO.-> (R-1) C (C-1)

//FIND 1 COMPLETE ROW-> res*=(n-i)-> res/=(i+1)

//BRUTE FORCE
//APPROACH- FIND SUM OF ALL SUBARRAYS, USING 2 FOR LOOPS
//TC- O(n*n)
//SC- O(1)


//BEST 
//APPROACH- KADANS ALGORITHM, NOT TAKING NEGATIVE SUM BEGGAGE FORWARD
//TC- O(n)
//SC- O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum=max(sum, 0);
            sum+=nums[i];
            ans=max(ans, sum);
        }
        return ans;
    }
};
