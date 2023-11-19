'''
Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.

Example 1

Input: X = abcd, Y = xycd

Output: 6

Explanation: Shortest Common Supersequence would be abxycd which is of length 6 and has both the strings as its subsequences.

Example 2

Input: X = efgh, Y = jghi

Output: 6

Explanation: Shortest Common Supersequence would be ejfghi which is of length 6 and has both the strings as its subsequences.

Your Task:
You don't have to take any input or print anything. Your task is to complete shortestCommonSupersequence() function that takes X, Y, m, and n as arguments and returns the length of the required string.

Expected Time Complexity: O(Length(X) * Length(Y)).
Expected Auxiliary Space: O(Length(X) * Length(Y)).

Constraints:
1<= |X|, |Y| <= 100
'''

class Solution:    
    def shortestCommonSupersequence(self, X, Y, m, n):
         dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
         for i in range(1,m+1):
             for j in range(1,n+1):
                 if X[i-1] == Y[j-1]:
                     dp[i][j] = dp[i-1][j-1] + 1
                 else:
                     dp[i][j] = max(dp[i-1][j],dp[i][j-1])
         res = m + n - dp[m][n]
         return res
