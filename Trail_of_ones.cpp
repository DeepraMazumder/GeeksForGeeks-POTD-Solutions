/*
Given a number n, find the number of binary strings of length n that contain consecutive 1's in them. Since, the number can be very large, return the answer after modulo with 1e9+7.

Example 1:

Input: n = 2

Output: 1

Explanation: There are 4 strings of length 2, the strings are 00, 01, 10, and 11. Only the string 11 has consecutive 1's.

Example 2:

Input: n = 5

Output: 19

Explanation: There are 19 strings having consecutive 1's.

Your Task:
You don't need to read input or print anything. Your task is to complete the function numberOfConsecutiveOnes() which takes an integer n and returns the number of binary strings that contain consecutive 1's in
them.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints
2 <= n <= 10^5
*/

class Solution 
{
    public:
        long long int mod=pow(10,9)+7;
        int numberOfConsecutiveOnes(int n) 
        {
            vector<int>dp(n+1,0);
            dp[0]=0,dp[1]=0,dp[2]=1;
            if(n<3)
            {
                return dp[n]%mod;
            }
            int a=0,b=1;
            for(int i=3; i<=n; i++)
            {
                int c=(a+b)%mod;
                dp[i]=((dp[i-1]*2)%mod+(c%mod));
                dp[i]=dp[i]%mod;
                a=b;
                b=c;
            }
            return dp[n]%mod;
        }
};
