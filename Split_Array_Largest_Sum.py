'''
Given an array arr[] of N elements and a number K., split the given array into K subarrays such that the maximum subarray sum achievable out of K subarrays formed is minimum possible. Find that possible subarray
sum.

Example 1:

Input:
N = 4, K = 3
arr[] = {1, 2, 3, 4}

Output: 4

Explanation: Optimal Split is {1, 2}, {3}, {4}. Maximum sum of all subarrays is 4, which is minimum possible for 3 splits. 

Example 2:

Input:
N = 3, K = 2
A[] = {1, 1, 2}

Output: 2

Explanation: Splitting the array as {1,1} and {2} is optimal. This results in a maximum sum subarray of 2.

Your Task:
You do not have to take any input or print anything. The task is to complete the function splitArray() which returns the maximum sum subarray after splitting the array into K subarrays such that maximum sum
subarray is minimum possible.

Expected Time Complexity: O(N*log(sum(arr))).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 105
1 ≤ K ≤ N
1 ≤ arr[i] ≤ 104
'''

class Solution:
    def bs(self,arr,divSum):
        ndiv,cs=1,0
        for a in arr:
            if cs+a<=divSum: cs+=a
            else:
                ndiv+=1
                cs=a
        return ndiv
    def splitArray(self, arr, N, K):
        # code here 
        l,r=max(arr),sum(arr)
        while l<=r:
            mid=(l+r)//2
            curr=self.bs(arr,mid)
            if curr>K: l=mid+1
            else: r=mid-1
        return l
