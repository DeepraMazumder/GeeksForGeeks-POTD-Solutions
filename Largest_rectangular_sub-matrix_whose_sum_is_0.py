'''
Given a matrix mat[][] of size N x M. The task is to find the largest rectangular sub-matrix by area whose sum is 0. If there are multiple solutions return the rectangle which starts from minimum column index.
If you still have multiple solutions return the one having greatest row number. If no such matrix is present return a zero (0) size matrix.

Example 1:

Input: N = 3, M = 3
mat[][] =  1, 2, 3
          -3,-2,-1
           1, 7, 5

Output:  1, 2, 3
        -3,-2,-1

Explanation: This is the largest sub-matrix, whose sum is 0.

Example 2:

Input: N = 4, M = 4
mat[][] = 9, 7, 16, 5
          1,-6,-7, 3
          1, 8, 7, 9
          7, -2, 0, 10

 Output: -6,-7
          8, 7
         -2, 0 
         
Your Task:
You don't need to read input or print anything. You just have to complete the function sumZeroMatrix() which takes a 2D matrix mat[][], its dimensions N and M as inputs and returns a largest sub-matrix, whose sum is 0.

Expected Time Complexity: O(N*M*M).
Expected Auxiliary Space: O(N*M).


Constraints:
1 <= N, M <= 100
-1000 <= mat[][] <= 1000
 '''

from typing import List
class Solution:
    def max_sub_sum(self, arr : List[List[int]]) -> List[List[int]]:
        n=len(arr)
        prefix_sum={0:-1}
        _sum=0
        s,e=0,0
        max_len=-float("inf")
        curr_len=0
        for i in range(n):
            _sum+=arr[i]
            if _sum in prefix_sum:
                curr_len=i-prefix_sum[_sum]
                if curr_len>max_len:
                    max_len=curr_len
                    e=i
                    s=prefix_sum[_sum]+1
            else:
                prefix_sum[_sum]=i
        return (s,e,max_len)
    def sumZeroMatrix(self, a):
        n,m=len(a),len(a[0])
        r1,r2,c1,c2,max_area=None,None,None,None,-float("inf")
        for i in range(m):
            arr=[0]*n
            for j in range(i,m):
                for k in range(n):
                    arr[k]+=a[k][j]
                s,e,length=self.max_sub_sum(arr)
                area=(e-s+1)*(j-i+1)
                if length>0 and area>max_area:
                    max_area=area
                    r1,r2,c1,c2=s,e,i,j
        result=[]
        for i in range(r1,r2+1):
            row_i=[]
            for j in range(c1,c2+1):
                row_i.append(a[i][j])
            result.append(row_i)
        return result
