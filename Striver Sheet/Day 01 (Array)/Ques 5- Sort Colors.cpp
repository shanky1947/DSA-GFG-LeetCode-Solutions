/*
Q Link- https://leetcode.com/problems/sort-colors/

75. Sort Colors
Medium

9113

397

Add to List

Share
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/



//BRUTE FORCE
//APPROACH- USE SORT FUNCTION OF STL
//TC- O(n*logn)
//SC- O(1)


//BETTER
//APPROACH- COUNT NUMBER OF ZEROES, ONES AND TWOS, ADD NUMBERS IN ARRAY ACCORDINGLY (TWO-PASS)
//TC- O(2n)
//SC- O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0, o=0, t=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                z++;
            else if(nums[i]==1)
                o++;
            else
                t++;
        }
        int i=0;
        while(z-- >0)
            nums[i++]=0;
        while(o-- >0)
            nums[i++]=1;
        while(t-- >0)
            nums[i++]=2;
    }
};


//BEST
//APPROACH- DUTCH NATIONAL FLAG ALGO- ONE PASS- MAINTAIN THREE VAIRABLES, 0-LOW-1->0, HIGH+1-N->2
//TC- O(n)
//SC- O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==1)
                mid++;
            else if(nums[mid]==0)
                swap(nums[low++], nums[mid++]);
            else if(nums[mid]==2)
                swap(nums[mid], nums[high--]);
        }
    }
};