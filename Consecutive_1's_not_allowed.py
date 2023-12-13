'''
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. Output your answer modulo 109 + 7.

Example 1:

Input: N = 3

Output: 5

Explanation: 5 strings are (000, 001, 010, 100, 101).

Example 2:

Input: N = 2

Output: 3

Explanation: 3 strings are (00,01,10).

Your Task:
You don't have to print answer or take inputs. Complete the function countStrings() which takes single integer n, as input parameters and returns an integer denoting the answer. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
'''

class Solution:
    def countStrings(self,n):
        modulo = 10**9 + 7
        fib_prev, fib_current = 1, 2
        for i in range(2, n + 1):
            fib_prev, fib_current = fib_current, (fib_prev + fib_current) % modulo
        return fib_current
