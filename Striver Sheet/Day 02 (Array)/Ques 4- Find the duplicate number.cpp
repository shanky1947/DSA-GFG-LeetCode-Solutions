/*
Q Link- https://leetcode.com/problems/find-the-duplicate-number/

287. Find the Duplicate Number
Medium

12160

1349

Add to List

Share
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?
*/


//BEST-MINE
//APPROACH- USE OF THING GIVEN THAT NO.S ARE IN (1-N), MODULO GIVES NUMBER, QUTIOTENT GIVES COUNT
//TC- O(2n)
//SC- O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sz=nums.size();
        for(int i=0;i<sz;i++){
            int idx=nums[i]%sz;
            nums[idx]+=sz;
        }
        int maxCount=0, idx=0;
        for(int i=0;i<sz;i++){
            int no=nums[i]%sz;
            int count=nums[no]/sz;
            if(count>maxCount){
                maxCount=count;
                idx=i;
            }
        }
        return nums[idx]%sz;
    }
};


//BEST 
//APPROACH- TORTOISE RABBIT, SLOW FAST POINTER APPROACH
//TC- O(n)
//SC- O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int rabbit = nums[0];
        do{
            tortoise = nums[tortoise];
            rabbit = nums[nums[rabbit]];
        }while(tortoise!=rabbit);
        
        tortoise = nums[0];
        while(tortoise != rabbit){
            tortoise = nums[tortoise];
            rabbit = nums[rabbit];
        }
        
        return rabbit;
    }
};