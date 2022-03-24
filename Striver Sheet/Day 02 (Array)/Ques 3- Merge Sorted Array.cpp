/*
Q Link- https://leetcode.com/problems/merge-sorted-array/

88. Merge Sorted Array
Easy

3874

371

Add to List

Share
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
 

Follow up: Can you come up with an algorithm that runs in O(m + n) time?

Accepted
1,304,420
Submissions
2,995,835
*/


//FIND 1 VALUE-> GIVEN ROW NO., COL NO.-> (R-1) C (C-1)

//FIND 1 COMPLETE ROW-> res*=(n-i)-> res/=(i+1)

//BRUTE FORCE
//APPROACH- FIND ALL PERMUTATIONS, FIND NEXT PERMUATION THAN GIVEN
//TC- O(n!*n)
//SC- O(n)


//BEST 
//APPROACH- FIND NEXT SMALLEST FROM LAST, REPLACE THAT WITH GREATER THAN LAST, REVERSE REMAINING FROM LAST
//TC- O(n)
//SC- O(n)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j, i=nums.size()-1;
        for(;i>0;i--){
            if(nums[i]>nums[i-1]){
                j=i-1;
                break;
            }
        }
        if(i==0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int k=nums.size()-1;
        for(;k>j;k--){
            if(nums[k]>nums[j])
                break;
        }
        swap(nums[k],nums[j]);
        reverse(nums.begin()+j+1, nums.end());
    }
};


//BETTER 
//APPROACH- SAME AS ABOVE, JUST CLEAN CODE
//TC- O(n)
//SC- O(n)

class Solution {
public:
    void reverse(int i, vector<int>& nums){
        int j=nums.size()-1;
        while(i<j){
            swap(nums[i++], nums[j--]);
        }
    }
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1])
            i--;
        if(i>=0){
            int j=nums.size()-1;
            while(j>0 && nums[j]<=nums[i])
                j--;
            cout<<i<<" "<<j;
            swap(nums[i], nums[j]);
        }
        reverse(i+1, nums);
    }
};

