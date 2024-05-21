/*
Given a array, arr[] of n integers, and a value x. Find the K closest elements to x in arr[].
Keep the following points in mind:

If x is present in the array, then it need not be considered.
If two elements have the same difference as x, the greater element is prioritized.
If sufficient elements are not present on the right side, take elements from the left and vice versa.
 
Example 1:

Input:
n = 13
arr[] = {12, 16, 22, 30, 35, 39, 42, 
         45, 48, 50, 53, 55, 56}
k = 4, x = 35

Output: 39 30 42 45

Explanation: 
First closest element to 35 is 39.
Second closest element to 35 is 30.
Third closest element to 35 is 42.
And fourth closest element to 35 is 45.

Example 2:

Input:
n = 5
arr[] = {1, 2, 3, 6, 10}
k = 3, x = 4

Output: 3 6 2

Explanation: 
First closest element is 3.
There are two elements 2 and 6 for which 
the difference with 4 is same i.e. 2.
So first take greatest number 6 
then the lower number 2.

Your Task:
You don't need to read input or print anything. Complete the function printKClosest() which takes arr[], n, k, and x as input parameters and returns an array of integers containing the K closest elements to x in
arr[].

Expected Time Complexity: O(log n + k)
Expected Auxiliary Space: O(k)

Constraints:
1 ≤ n ≤ 10^5
1 ≤ k ≤ n
1 ≤ x ≤ 10^6
1 ≤ arr[i] ≤ 10^6
*/

class Solution 
{
    public:
        int findCrossOver(vector<int>& arr, int low, int high, int x) 
        {
            if (arr[high] <= x) 
                return high;
            if (arr[low] > x) 
                return low;
            int mid = (low + high) / 2;
            if (arr[mid] <= x && arr[mid + 1] > x) 
                return mid;
            else if (arr[mid] < x) 
                return findCrossOver(arr, mid + 1, high, x);
            return findCrossOver(arr, low, mid - 1, x);
        }
        vector<int> printKClosest(vector<int> arr, int n, int k, int x) 
        {
            int crossoverIndex = findCrossOver(arr, 0, n - 1, x);
            int leftIndex = crossoverIndex;
            int rightIndex = crossoverIndex + 1;
            if (leftIndex >= 0 && arr[leftIndex] == x) 
                leftIndex--;
            vector<int> closestElements;
            for (int i = 0; i < k; i++) 
            {
                if (leftIndex >= 0 && rightIndex < n) 
                {
                    int leftDiff = x - arr[leftIndex];
                    int rightDiff = arr[rightIndex] - x;
                    if (leftDiff < rightDiff) 
                    {
                        closestElements.push_back(arr[leftIndex]);
                        leftIndex--;
                    } 
                    else 
                    {
                        closestElements.push_back(arr[rightIndex]);
                        rightIndex++;
                    }
                } 
                else if (leftIndex >= 0) 
                { 
                    closestElements.push_back(arr[leftIndex]);
                    leftIndex--;
                } 
                else 
                { 
                    closestElements.push_back(arr[rightIndex]);
                    rightIndex++;
                }
            }
            return closestElements;
        }
};
