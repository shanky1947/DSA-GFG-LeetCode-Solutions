/*
Q Link- https://leetcode.com/problems/pascals-triangle/

118. Pascal's Triangle
Easy

5148

198

Add to List

Share
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30
*/


//FIND 1 VALUE-> GIVEN ROW NO., COL NO.-> (R-1) C (C-1)

//FIND 1 COMPLETE ROW-> res*=(n-i)-> res/=(i+1)

//BRUTE FORCE
//APPROACH- TWO VECTORS, CURR, PREV, TWO LOOP, 1 FOR ROW, 1 FOR COL
//TC- O(n*n)
//SC- O(n)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev;
        prev.push_back(1);
        ans.push_back(prev);
        
        vector<int> curr;
        for(int i=1;i<numRows;i++){
            curr.push_back(1);
            for(int j=0;j<prev.size()-1;j++){
                curr.push_back(prev[j]+prev[j+1]);
            }
            curr.push_back(1);
            ans.push_back(curr);
            prev=curr;
            curr.clear();
        }
        return ans;
    }
};


//BETTER 
//APPROACH- SIMILAR TO ABOVE, JUST RESIZE OF ARRAY
//TC- O(n*n)
//SC- O(n*n)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        
        for(int i=0;i<numRows;i++){
            ans[i].resize(i+1);
            ans[i][0]=ans[i][i]=1;
            
            for(int j=1;j<i;j++){
                ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
            }
        }
        return ans;
    }
};

