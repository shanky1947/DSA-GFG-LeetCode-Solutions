/*
Q Link- https://leetcode.com/problems/next-permutation/

31. Next Permutation
Medium

9154

3092

Add to List

Share
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
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

