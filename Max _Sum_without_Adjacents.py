'''
Given an array Arr of size N containing positive integers. Find the maximum sum of a any possible subsequence such that no two numbers in the subsequence should be adjacent in Arr.

Example 1:

Input:
N = 6
Arr[] = {5, 5, 10, 100, 10, 5}

Output: 110

Explanation: If you take indices 0, 3 and 5, then Arr[0]+Arr[3]+Arr[5] = 5+100+5 = 110.

Example 2:

Input:
N = 4
Arr[] = {3, 2, 7, 10}

Output: 13

Explanation: 3 and 10 forms a non continuous subsequence with maximum sum.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findMaxSum() which takes the array of integers Arr and N as parameters and returns an the maximum sum possible of any
valid subsequence.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arri ≤ 105
'''

class Solution:
    def findMaxSum(self,arr, n):
        prev = 0
        curr =0
        sum = 0
        for i in range(0 , n):
            sum = arr[i] + curr
            curr = prev
            prev = max(prev , sum)
        return prev
