'''
Given an array a of length n and a number k, find the largest sum of the subarray containing at least k numbers. It is guaranteed that the size of array is at-least k.

Example 1:

Input : 
n = 4
a[] = {-4, -2, 1, -3}
k = 2

Output : -1

Explanation : The sub-array of length at-least 2 that produces greatest sum is {-2, 1} 

Example 2:

Input :
n = 6 
a[] = {1, 1, 1, 1, 1, 1}
k = 2

Output : 6

Explanation : The sub-array of length at-least 2 that produces greatest sum is {1, 1, 1, 1, 1, 1}

Your Task:  
You don't need to read input or print anything. Your task is to complete the function maxSumWithK() which takes the array a[], its size n and an integer k as inputs and returns the value of the largest sum of
the subarray containing at least k numbers.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 105
-105 <= a[i] <= 105
1 <= k <= n
'''

class Solution():
    def maxSumWithK(self, arr, n, k):
        i,j = 0,0
        currsum = 0
        ans = float('-inf')
        last = 0   
        while j<n:
            currsum += arr[j]
            if j-i+1 == k:
                ans = max(ans,currsum)
            elif j-i+1 > k:
                last += arr[i] 
                i += 1
                if last<0: 
                    currsum -= last
                    last = 0
                ans = max(ans,currsum)
            j += 1        
        return ans
