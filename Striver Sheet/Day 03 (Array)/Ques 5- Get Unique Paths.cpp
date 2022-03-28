/*
Q Link- https://leetcode.com/problems/unique-paths/

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100
Accepted
896,563
Submissions
1,500,154
*/



//RECURSION
//APPROACH- RETURN TOTAL OF NUMBER OF STEPS COMING FROM BOTTOM AND RIGHT, IF REACHED TO FINAL RETURN ONLY 1 STEP
//TC- O(2^(m*n))
//SC- O(1) or space of recursion stack (max(m,n))'

class Solution {
public:
    int dp[105][105];
    int helper(int i, int j, int m, int n){
        if(i>=m || j>=n)
            return 0;
        if(i==m-1, j==n-1)
            return 1;
        return (helper(i+1, j, m, n) + helper(i, j+1, m, n));
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, m, n);
    }
};


//MEMOISATION
//APPROACH- USE DP ARRAY TO STORE ANSWER
//TC- O(m*n)
//SC- O(m*n)

class Solution {
public:
    int dp[105][105];
    int helper(int i, int j, int m, int n){
        if(i>=m || j>=n)
            return 0;
        if(i==m-1, j==n-1)
            return 1;
        if(dp[i][j]>-1)
            return dp[i][j];
        dp[i][j]=(helper(i+1, j, m, n) + helper(i, j+1, m, n));
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, m, n);
    }
};



//DP
//APPROACH- WILL START FROM END POINT, WILL GO IN REVERSE DIRECTION
//TC- O(m*n)
//SC- O(m*n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[105][105];

        for(int i=m-1;i>=0;i--)
            dp[i][n-1]=1;
        for(int j=n-1;j>=0;j--)
            dp[m-1][j]=1;

        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};