/*
Q Link- https://leetcode.com/problems/powx-n/

50. Pow(x, n)
Medium

4204

5210

Add to List

Share
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104
Accepted
865,189
Submissions
2,683,673
*/


//BRUTE FORCE
//APPROACH- USE LOOP FROM 1 TO N AND MULTIPLY X N TIMES
//TC- O(n)
//SC- O(1)



//BEST
//APPROACH- BINARY EXPONENTIATION, 
//TC- O(log(n))
//SC- O(1)

class Solution {
public:
    double myPow(double x, int nn) {
        long n=(long)nn;  //to avoid overflow while converting to pos as neg int has 1 extra range than pos int
        
        bool negFlag=false; //to divide by 0 in end, if neg no
        if(n<0){
            negFlag=true;
            n=(-1)*n;         //making positive, will divide by 1 in end
        }
        
        double ans=1.0;
        while(n>0){
            if(n%2==0){
                x = x * x;      //if even power, x*x and pow divide by 2
                n = n/2;
            }
            else{
                ans = ans * x;   //if odd power, x muliplied by existing ans
                n = n - 1;
            }
        }
        //In end, if only even pow, we will have 1, so else will always execute
        
        if(negFlag)
            ans=(double)(1.0)/ans;
        return ans;
    }
};