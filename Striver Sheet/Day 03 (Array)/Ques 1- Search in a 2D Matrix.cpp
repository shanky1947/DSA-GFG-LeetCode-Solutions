/*
Q Link- https://leetcode.com/problems/search-a-2d-matrix/

74. Search a 2D Matrix
Medium

6437

251

Add to List

Share
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
Accepted
689,377
Submissions
1,605,531
*/



//BRUTE FORCE
//APPROACH- USE TWO LOOPS, ITERATE IN COMPLETE MATRIX
//TC- O(m*n)
//SC- O(1)


//BETTER
//APPROACH- ITERATE ON LAST COLUMN AND FIND JUST SMALLEST ROW, FIND NO. IN THAT ROW
//TC- O(m+n)
//SC- O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int i=0;
        for(;i<m;i++){
            if(matrix[i][n-1]>=target)
                break;
        }
        if(i==m)
            return false;
        for(int j=0;j<n;j++){
            if(matrix[i][j]==target)
                return true;
        }
        return false;
    }
};


//BEST
//APPROACH- BINARY SEARCH, MAP MIDDLE TO MATRIX- MATRIX[MID/M][MID%M]
//TC- O(log(m*n))
//SC- O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int si=0, ei=(n*m-1);
        while(si<=ei){
            int mid=(si+ei)/2;
            
            int row=mid/m;   //number of times divided gives row no
            int col=mid%m;   //extra remaining part gives col no
            
            if(target==matrix[row][col])
                return true;
            else if(target>matrix[row][col])
                si=mid+1;
            else
                ei=mid-1;
        }
        return false;
    }
};