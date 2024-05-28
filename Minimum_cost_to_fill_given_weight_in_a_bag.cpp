/*
Given an array cost[] of positive integers of size n and an integer w, where cost[i] represents the cost of an i kg packet of oranges, the task is to find the minimum cost to buy exactly w kg of oranges. The cost
array has a 1-based indexing. If buying exactly w kg of oranges is impossible, then return -1.

Note:
1. cost[i] = -1 means that i kg packet of orange is unavailable.
2. It may be assumed that there is an infinite supply of all available packet types.

Example 1:

Input: 
n = 5
cost[] = {20, 10, 4, 50, 100} 
w = 5

Output: 14

Explanation: Purchase the 2kg packet for 10 coins and the 3kg packet for 4 coins to buy 5kg of oranges for 14 coins.

Example 2:

Input: 
n = 5
cost[] = {-1, -1, 4, 3, -1}
w = 5

Output: -1

Explanation: It is not possible to buy 5 kgs of oranges.

Your Task:  
You don't need to read input or print anything. Complete the function minimumCost() which takes integers n and w, and integer array cost[] as input parameters and returns the minimum cost to buy exactly w kg of 
oranges, If buying exactly w kg of oranges is impossible, then return -1.

Expected Time Complexity: O(n*w)
Expected Auxiliary Space: O(n*w)

Constraints:
1 ≤ n, w ≤ 2*10^2
1 ≤ cost[i] ≤ 10^5
cost[i] ≠ 0
*/

class Solution 
{
    public:
        int minimumCost(int n, int w, vector<int> &c) 
        {
            vector<vector<int>>dp(n+1,vector<int>(w+1,0));
            for(int j=0;j<=w;j++)
                dp[0][j]=9999;
            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<=w;j++)
                {
                    if(i==0||j==0)
                        continue;
                    else
                    {
                        if(i<=j&&c[i-1]!=-1)
                        {
                            dp[i][j]=min(c[i-1]+dp[i][j-i],dp[i-1][j]);
                        }
                        else
                            dp[i][j]=dp[i-1][j];
                    }
                    
                }
            }
            return dp[n][w]==9999?-1:dp[n][w];
        }
};
