'''
Given a square matrix of size n*n. The task is to find the determinant of this matrix.

Example 1:

Input:
n = 4
matrix[][] = {{1, 0, 2, -1},
              {3, 0, 0, 5},
              {2, 1, 4, -3},
              {1, 0, 5, 0}}
              
Output: 30

Explanation: Determinant of the given matrix is 30.

Example 2:

Input:
n = 3
matrix[][] = {{1, 2, 3},
              {4, 5, 6},
              {7, 10, 9}}
              
Output: 12

Explanation: Determinant of the given matrix is 12.

Your Task:
You don't need to read input or print anything. Complete the function determinantOfMatrix() that takes matrix and its size n as input parameters and returns the determinant of the matrix.

Expected Time Complexity: O(N4)
Expected Auxiliary Space: O(N2)

Constraints:
1 <= N <= 10
-10 <= mat[i][j] <= 10
'''

class Solution:
    def determinantOfMatrix(self,matrix,n):
        def compute(row, col_s):
            nonlocal n 
            if row == n:
                return 1
            sign = 1
            ret = 0
            for c in range(n):
                if c not in col_s:
                    col_s.add(c)
                    ret += sign*matrix[row][c]*compute(row+1, col_s)
                    col_s.remove(c)
                    sign *= -1
            return ret
        return compute(0, set()) 
