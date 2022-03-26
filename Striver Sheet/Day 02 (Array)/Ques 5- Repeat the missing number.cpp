/*
Q Link- https://www.interviewbit.com/problems/repeat-and-missing-number-array/

Repeat and Missing Number Array
Medium

227

24

Add to favorites
Asked In:
AMAZON
There are certain problems which are asked in the interview to also check how you take care of overflows in your problem.

This is one of those problems.

Please take extra care to make sure that you are type-casting your ints to long properly and at all places. Try to verify if your solution works if number of elements is as large as 105

Food for thought :

Even though it might not be required in this problem, in some cases, you might be required to order the operations cleverly so that the numbers do not overflow.
For example, if you need to calculate n! / k! where n! is factorial(n), one approach is to calculate factorial(n), factorial(k) and then divide them.
Another approach is to only multiple numbers from k + 1 ... n to calculate the result.
Obviously approach 1 is more susceptible to overflows.
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
*/



//BETTER
//APPROACH- FIRST FIND DUPLICATE, THEN (SUM FROM 1 TO N)-(SUM OF ARRAY-DUPLICATE NO.)=MISSING NUMBER
//TC- O(3N)
//SC- O(1)


//BETTER
//APPROACH- X-Y=S1, X*X-Y*Y=S2 GET VALUE X+Y FROM HERE, THEN FIND VALUE OF X AND Y BY SOLVING BOTH
//TC- O(N)
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
//APPROACH- USING XOR
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