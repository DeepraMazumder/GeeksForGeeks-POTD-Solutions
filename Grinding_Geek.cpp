/*
GeeksforGeeks has introduced a special offer where you can enroll in any course, and if you manage to complete 90% of the course within 90 days, you will receive a refund of 90%.

Geek was fascinated by this offer. This offer was valid for only n days, and each day a new course was available for purchase. Geek decided that if he bought a course on some day, he will complete that course on
the same day itself and redeem floor[90% of cost of the course] amount back. Find the maximum number of courses that Geek can complete in those n days if he had total amount initially.

Note: On any day, Geek can only buy the new course that was made available for purchase that day.

Example 1:

Input:
n = 2
total = 10
cost = [10, 9]

Output: 2

Explanation: Geek can buy the first course for 10 amount, complete it on the same date and redeem 9 back. Next, he can buy and complete the 2nd course too.

Example 2:

Input:
n = 11
total = 10
cost = [10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

Output: 10

Explanation: Geek can buy and complete all the courses that cost 1.

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function max_courses() that takes N the number of days, the total amount, and the cost array as
input argument and return the maximum amount of courses that could be purchased.

Expected Time Complexity: O(n*total)
Expected Auxiliary Space: O(n*total)

Constraints:
1 <= n <= 1000
0 <= total <= 1000
1 <= cost[i] <= 1000
*/

class Solution
{
    public:
    int help(int ind, int n,int total, vector<int> &cost,  vector<vector<int>> &dp)
    {
        if(ind==n) return 0;
        if(dp[ind][total]!=-1) return dp[ind][total];
        if(total < cost[ind])
        {
            return dp[ind][total] = help(ind+1,n, total, cost,dp);
        }
        else
        {
            int leftAmount = total - cost[ind];
            int refund = cost[ind]*0.9;
            leftAmount += refund;
            
            int pick = 1 + help(ind+1,n, leftAmount, cost,dp);
            int notPick = help(ind+1,n, total, cost,dp);
            return dp[ind][total] = max(pick, notPick);
        }
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> dp(n+1, vector<int>(total+1, -1));
        return help(0,n,total,cost, dp);
    }
};
