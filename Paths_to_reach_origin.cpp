/*
You are standing on a point (x, y) and you want to go to origin (0, 0) by taking steps either left or up i.e. from each point you are allowed to move either in (x-1, y) or (x, y-1). Find the number of paths from
point to origin.

Example 1:

Input: x = 3, y = 0 

Output: 1

Explanation: Path used was -  (3,0)  --> ( 2,0) --> (1,0) --> (0,0).We can see that there is no other path than this, so we return 1.

Example 2:

Input: x = 3, y = 6

Output: 84 

Explanation: There are total 84 possible paths.

Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function ways() that takes integer x and  y as parameters and
returns the total number of paths from point(x,y) to the origin(0,0) % 1000000007.

Expected Time Complexity: O(x*y).
Expected Auxiliary Space: O(x*y).

Constraints:
1 ≤ x, y ≤ 500
*/

class Solution 
{
    public:
        const int mod = 1000000007;
        int ways(int n, int m) 
        {
            vector<vector<int>> cash(n+1, vector<int>(m+1, -1));
            return helper(n, m, cash);
        }
        int helper(int n, int m, vector<vector<int>>& cash) 
        {
            if (n == 0 || m == 0)
                return 1;
            if (cash[n][m] != -1)
                return cash[n][m];
            cash[n][m] = (helper(n-1, m, cash) + helper(n, m-1, cash)) % mod;
            return cash[n][m];
        }
};
