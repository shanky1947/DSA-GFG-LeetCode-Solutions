/*
Q Link- https://leetcode.com/problems/set-matrix-zeroes/

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


//BEST
//APPROACH- CONSIDER 1ST ROW AND COLUMN AS REFERNCE FOR PUTTING 0 VALUE
//TC- O(2*m*n+m+n)
//SC- O(1)
//MY CODE

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int columnFlag=0;  //if first row contains any 0 value   
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0)
                columnFlag=1;
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        //filling all values except 1st row and 1st column
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }
        
        //1st column-> 0,0 is deciding point for 1st column
        for(int j=0;j<n;j++){
            if(matrix[0][0]==0)
                matrix[0][j]=0;
        }
        //1st row-> if flag is set, then 1st row is 0
        if(columnFlag==1){
            for(int i=0;i<m;i++)
                matrix[i][0]=0;
        }
    }
};



//TC- O(2*m*n)
//SC- O(1)
//STRIVER CODE

void setZeroes(vector < vector < int >> & matrix) {
  int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
  for (int i = 0; i < rows; i++) {
    //checking if 0 is present in the 0th column or not
    if (matrix[i][0] == 0) col0 = 0;
    for (int j = 1; j < cols; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }
  //traversing in the reverse direction and
  //checking if the row or col has 0 or not
  //and setting values of matrix accordingly.
  for (int i = rows - 1; i >= 0; i--) {
    for (int j = cols - 1; j >= 1; j--) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
    if (col0 == 0) {
      matrix[i][0] = 0;
    }

  }

}