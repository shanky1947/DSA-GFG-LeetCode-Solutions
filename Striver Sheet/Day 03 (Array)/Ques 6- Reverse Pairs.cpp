/*
Q Link- https://leetcode.com/problems/reverse-pairs/

493. Reverse Pairs
Hard

2639

176

Add to List

Share
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1
Accepted
79,459
Submissions
266,785
*/



//BRUTE FORCE
//APPROACH- USE TWO LOOPS
//TC- O(n*n)
//SC- O(1)

//BEST
//APPROACH- USE MERGE SORT CONCEPT TO CALCULATE SMALLER NUMBERS IN RIGHT PART-> (MID-I+1), USE SEPERATE LOOPS FOR CACULATION OF COUNT AND SORTING
//TC- O(n*logn+n)
//SC- O(n)

class Solution {
public:
    int merge(vector<int>& nums, int si, int mid, int ei){
        int i=si, j=mid+1;
        int count=0;
        while(i<=mid && j<=ei){
            if(nums[i]>(2*(long)nums[j])){
                count+=(mid-i+1);
                j++;
            }
            else
                i++;
        }
        
        i=si, j=mid+1;
        int k=0, temp[ei-si+1];
        while(i<=mid && j<=ei){
            if(nums[i]<=nums[j])
                temp[k++]=nums[i++];
            else
                temp[k++]=nums[j++];
        }
        
        while(i<=mid)
            temp[k++]=nums[i++];
        while(j<=ei)
            temp[k++]=nums[j++];
        for(int i=si, k=0; i<=ei; i++, k++)
            nums[i]=temp[k];
        return count;
    }
    int mergeSort(vector<int>& nums, int si, int ei){
        int count=0;
        if(si<ei){
            int mid=(si+ei)/2;
            count+=mergeSort(nums, si, mid);
            count+=mergeSort(nums, mid+1, ei);
            
            count+=merge(nums, si, mid, ei);
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};