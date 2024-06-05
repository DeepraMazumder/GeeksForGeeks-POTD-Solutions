/*
Given two arrays of integers a[] and b[] of size n and m, the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays
equal.

Example 1:

Input: n = 6, m = 4, a[] = {4, 1, 2, 1, 1, 2}, b[] = (3, 6, 3, 3)

Output: 1

Explanation: Sum of elements in a[] = 11, Sum of elements in b[] = 15, To get same sum from both arrays, we can swap following values: 1 from a[] and 3 from b[]

Example 2:

Input: n = 4, m = 4, a[] = {5, 7, 4, 6}, b[] = {1, 2, 3, 8}

Output: 1

Explanation: We can swap 6 from array a[] and 2 from array b[]

Your Task
You don't need to read or print anything. You need to complete the function findSwapValues() that takes array a, array b, integer n, and integer m as parameters and returns 1 if there exists any such pair
otherwise returns -1.

Expected Time Complexity: O(mlogm+nlogn).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ n, m ≤ 10^6
0 <= a[i], b[i] <= 10^5
*/

class Solution 
{
    public:
        int findSwapValues(int a[], int n, int b[], int m) {
            unordered_map<int, int> mp;
            int sum1 = 0;
            int sum2 = 0;
            for(int i=0; i<n; i++)
            {
                sum1 += a[i];
            }
            for(int i=0; i<m; i++)
            {
                sum2 += b[i];
                mp[b[i]] = i;
            }
            int totalSum = sum1 + sum2;
            if(totalSum % 2 == 1)
            {
                return -1;
            }
            int difference = (totalSum/2) - sum1;
            for(int i=0; i<n; i++)
            {
                int x = a[i];
                int res = x + difference;
                if(mp.find(res) != mp.end())
                {
                    return 1;
                }
            }
            return -1;
        }
};
