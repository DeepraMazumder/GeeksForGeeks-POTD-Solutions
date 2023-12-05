'''
Given an array arr[] denoting heights of N towers and a positive integer K. For each tower, you must perform exactly one of the following operations exactly once.
Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.
You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.

Example 1:

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}

Output: 5

Explanation: The array can be modified as {1+k, 5-k, 8-k, 10-k} = {3, 3, 6, 8}. The difference between the largest and the smallest is 8-3 = 5.

Example 2:

Input:
K = 3, N = 5
Arr[] = {3, 9, 12, 16, 20}

Output: 11

Explanation: The array can be modified as {3+k, 9+k, 12-k, 16-k, 20-k} -> {6, 12, 9, 13, 17}. The difference between the largest and the smallest is 17-6 = 11. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function getMinDiff() which takes the arr[], n, and k as input parameters and returns an integer denoting the minimum difference.

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(N)

Constraints
1 ≤ K ≤ 109
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ 109
'''

class Solution:
    def getMinDiff(self, arr, n, k):
        arr.sort()
        diff=arr[-1]-arr[0]
        mx=0
        mn=0
        for idx,val in enumerate(arr):
            if idx==0 or val<k or arr[-1]<k:
                continue
            mx=max(arr[idx-1]+k,arr[-1]-k)
            mn=min(arr[0]+k,val-k)
            diff=min(diff,abs(mx-mn))
        return diff
