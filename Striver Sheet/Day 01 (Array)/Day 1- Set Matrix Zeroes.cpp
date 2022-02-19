/*
73. Set Matrix Zeroes
Medium

5882

455

Add to List

Share
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

//BRUTE FORCE
//APPROACH- MAKE A COPY OF MATRIX AND MAKE CHANGES IN THAT DUMMY ARRAY
//TC- O(m*n*(m+n))
//SC- O(m*n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> copy(m, vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                copy[i][j]=matrix[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<n;k++)
                        copy[i][k]=0;
                    for(int k=0;k<m;k++)
                        copy[k][j]=0;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=copy[i][j];
            }
        }
    }
};

//BETTER 
//APPROACH- TAKE TWO DUMMY ARRAYS OF SIZE OF ROW AND COLUMN AND MAKE THEM 1 AS FIND 0
//TC- O(m*n)
//SC- O(m+n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int *row = new int[m]();
        int *col = new int[n]();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        // for(int i=0;i<m;i++){
        //     if(row[i]==1){
        //         for(int j=0;j<n;j++){
        //             matrix[i][j]=0;
        //         }
        //     }
        // }
        // for(int j=0;j<n;j++){
        //     if(col[j]==1){
        //         for(int i=0;i<m;i++){
        //             matrix[i][j]=0;
        //         }
        //     }
        // }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]==1 || col[j]==1)
                    matrix[i][j]=0;
            }
        }
    }
};