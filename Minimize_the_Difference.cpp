/*
You are given an array arr of size n. You have to remove a subarray of size k , such that the difference between the maximum and minimum values of the remaining array is minimized.
Find the minimum value obtained after performing the operation of the removal of the subarray and return it.

Example 1:

Input:
n = 5
k = 3
arr = {1, 2, 3, 4, 5}

Output: 1

Explanation: We can remove first subarray of length 3(i.e. {1, 2, 3}) then remaining array will be {4,5} and the difference of maximum and minimum element will be 1 i.e 5 - 4 = 1

Example 2:

Input:
n = 6
k = 3
arr = {2, 3, 1, 4, 6, 7}

Output: 2

Explanation:
If we remove the subarray {2,3,1} then remaining array will be {4,6,7} and the difference  = 7-4 = 3
If we remove the subarray {3,1,4} then remaining array will be {2,6,7} and the difference  = 7-2 = 5
If we remove the subarray {1,4,6} then remaining array will be {2,3,7} and the difference  = 7-2 = 5
If we remove the subarray {4,6,7} then remaining array will be {2,3,1} and the difference  = 3-1 = 2
So the answer will be min(3,5,5,2) = 2

Your Task: 
You have to complete the function minimizeDifference( ), which takes two integers n and k and an integer array arr of size n. You have to return the minimum difference of maximum and minimum elements of the
remaining array after removing one k length subarray of it.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
2 <= n <= 10^5
1 <= k <= n-1
0 <= arr[i] <= 10^9
*/

class Solution 
{
    public:
        int minimizeDifference(int n, int k, vector<int> &arr) 
        {
            vector<int> suffixMin(n);
            vector<int> suffixMax(n);
            int maxi = arr[n-1];
            int mini = arr[n-1];
            for(int i=n-1;i>=0;i--)
            {
                mini = min( mini, arr[i]);
                maxi = max( maxi , arr[i]);
                suffixMin[i]  = mini;
                suffixMax[i]  = maxi;
            }
            int ans = INT_MAX;
            int premax = arr[0];
            int premin = arr[0];
            ans = min( ans , suffixMax[k] - suffixMin[k]);
            for(int i=1;i < n-k;i++)
            {
                int minval = min(premin , suffixMin[i+k]);
                int maxval = max(premax , suffixMax[i+k]);
                ans = min(ans , maxval - minval);
                premax = max(premax , arr[i]);
                premin = min(premin , arr[i]);
            }
            ans = min(ans  , premax - premin);
            return ans;
        }
};
