/*
Q Link- https://leetcode.com/problems/majority-element-ii/

229. Majority Element II
Medium

4575

272

Add to List

Share
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 

Follow up: Could you solve the problem in linear time and in O(1) space?

Accepted
277,444
Submissions
659,132
*/




//BRUTE FORCE
//APPROACH- USING TWO LOOPS, COUNT FOR EACH ELEMENT COUNT AND CHECK GREATER THAN N/3
//TC- O(n*n)
//SC- O(1)


//BETTER
//APPROACH- USING EXTRA ARRAY OR HASHMAP, TO STORE COUNT OF NUMBERS
//TC- O(n)
//SC- O(n)


//BEST
//APPROACH- EXTENDED MOORES VOTING ALGO, AT MAX 2 NOS, TAKE TWO ELE1, ELE2, CANCEL OUT BOTH WITH ANY UNEQUAL NO
//TC- O(n)
//SC- O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1, ele2;
        int c1=0, c2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==ele1){
                c1++;
            }
            else if(nums[i]==ele2){
                c2++;
            }
	//1st check for equality otherwise, ele2=1, c1=0, in this case, ele1 will be given as 1 rather than incrementing c2 of ele2
            else if(c1==0){     
                ele1=nums[i];
                c1=1;
            }
            else if(c2==0){
                ele2=nums[i];
                c2=1;
            }
	//decrementing both in else, treat both as one no. in moors for n/2, cutting both with any unequal no
            else{    
                c1--;
                c2--;
            }
        }
        
	//getting count, cant check with c1 or c2>0, if only 1 number as answer it will no work
        int tc1=0, tc2=0;  
        for(int i=0;i<n;i++){
            if(nums[i]==ele1)
                tc1++;
            else if(nums[i]==ele2)
                tc2++;
        }
        
        vector<int> ans;
        if(tc1>(n/3))
            ans.push_back(ele1);
        if(tc2>(n/3))
            ans.push_back(ele2);
        return ans;
    }
};