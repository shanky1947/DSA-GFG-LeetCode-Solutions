/*
Q Link- hhttps://leetcode.com/problems/majority-element/

169. Majority Element
Easy

9138

328

Add to List

Share
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
Accepted
1,178,583
Submissions
1,878,030
*/




//BRUTE FORCE
//APPROACH- USING TWO LOOPS, COUNT FOR EACH ELEMENT COUNT AND CHECK GREATER THAN N/2
//TC- O(n*n)
//SC- O(1)


//BETTER
//APPROACH- USING EXTRA ARRAY OR HASHMAP, TO STORE COUNT OF NUMBERS
//TC- O(n)
//SC- O(n)


//BEST
//APPROACH- MOORES VOTING ALGO, ALL OTHER NUMBERS WILL GET CANCELLED OUT BY NUMBER WHICH APPEAR MORE THAN HALF
//TC- O(n)
//SC- O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, ele;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                ele=nums[i];
                count=1;
            }
            else if(nums[i]==ele)
                count++;
            else
                count--;
        }
        return ele;
    }
};