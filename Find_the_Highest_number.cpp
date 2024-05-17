/*
Given an integer array a[] of size n, find the highest element of the array. The array will either be strictly increasing or strictly increasing and then strictly decreasing.

Note: a[i] != a[i+1] 

Example 1:

Input:
11
1 2 3 4 5 6 5 4 3 2 1

Output: 6

Explanation: Highest element of array a[] is 6.

Example 2:

Input:
5
1 2 3 4 5

Output: 5

Explanation: Highest element of array a[] is 5.

Your Task:
You don't need to read or print anything. Your task is to complete the function findPeakElement() which takes integer n, and the array a[] as the input parameters and returns the highest element of the array.

Expected Time Complexity: O(log(n))
Expected Space Complexity: O(1)

Constraints:
2 <= n <= 10^6
1 <= a[i] <= 10^6
*/

class Solution 
{
    public:
        int findPeakElement(vector<int>& a) 
        {
            return *(max_element(a.begin(),a.end()));
        }
};
