'''
Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colors.
Since the answer can be large return it modulo 109 + 7.

Example 1:

Input:
n = 3
k = 2 

Output: 6

Explanation: We have following possible combinations: http://cdncontribute.geeksforgeeks.org/wp-content/uploads/paintFence.png

Example 2:

Input:
n = 2
k = 4 

Output: 16

Explanation: After coloring first post with 4 possible combinations, you can still color next posts with all 4 colors. Total possible combinations will be 4x4=16

Your Task:
Since, this is a function problem. You don't need to take any input or print anything, as it is already accomplished by the driver code. 
You just need to complete the function countWays() that takes n and k as parameters and returns the number of ways in which the fence can be painted (modulo 109 + 7).

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 5000
1 ≤ K ≤ 100
'''

class Solution:
    def countWays(self,n,k):
        #code here.
        M = 10**9+7
        same, diff = 0, k
        for i in range(1, n):
            diff, same = (same+diff)*(k-1)%M, diff
        return (same+diff)%M
