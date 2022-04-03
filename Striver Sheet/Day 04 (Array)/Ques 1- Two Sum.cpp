/*
Q Link- https://leetcode.com/problems/two-sum/

1. Two Sum
Easy

30789

969

Add to List

Share
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
Accepted
6,304,765
Submissions
13,018,902
*/



//BRUTE FORCE
//APPROACH- USE TWO LOOPS, FOR EACH NO IN I, FIND TARGET-I IN J
//TC- O(n*n)
//SC- O(1)


//BETTER
//APPROACH- TWO POINTER APPRAOCH, SORT ARRAY, TAKE TWO POINTERS AT 0 AND SIZE-1, <TARGET I++, >TARGET J--, =TARGET ANS, TEMP ARRAY AS INDEX CHANGES AFTER SORT
//TC- O(n*logn)
//SC- O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp=nums;
        
        int i=0, j=nums.size()-1, t1, t2;
        vector<int> ans;
        
        sort(nums.begin(), nums.end());
        
        while(i<j){
            if(nums[i]+nums[j]>target){
                j--;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{
                t1=nums[i];
                t2=nums[j];
                break;
            }
        }
        for(int i=0;i<temp.size();i++){
            if(t1==temp[i])
                ans.push_back(i);
            else if(t2==temp[i])
                ans.push_back(i);
        }
        return ans;
    }
};


//BEST
//APPROACH- HASH MAP, SEARCH FOR TARGET-I IN MAP, IN REPEATED CASE, NEW INDEX WILL BE STORED, FOR 3+3=6, MAP INDEX NOT EQUAL TO CURRENT INDEX
//TC- O(2n)
//SC- O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> map;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
            map[nums[i]]=i;
        
        for(int i=0;i<nums.size();i++){
            int no=target-nums[i];
            if(map[no]>0 && map[no]!=i){
                ans.push_back(i);
                ans.push_back(map[no]);
                return ans;
            }
        }
        return ans;
    }
};


--OR

//MORE OPTIMIZED, ADDED VALUE IN MAP, AFTER CHECKING
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> map;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            int no=target-nums[i];
            if(map.find(no) != map.end()){
                ans.push_back(i);
                ans.push_back(map[no]);
                return ans;
            }
            map[nums[i]]=i;
        }
        return ans;
    }
};