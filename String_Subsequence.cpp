/*
Given two strings, s1 and s2, count the number of subsequences of string s1 equal to string s2.

Return the total count modulo 1e9+7.

Example 1:

Input: s1 = geeksforgeeks, s2 = gks

Output: 4

Explaination: We can pick characters from s1 as a subsequence from indices {0,3,4}, {0,3,12}, {0,11,12} and {8,11,12}.So total 4 subsequences of s1 that are equal to s2.

Example 2:

Input: s1 = problemoftheday, s2 = geek

Output: 0

Explaination: No subsequence of string s1 is equal to string s2.

Your Task:
You don't need to read input or print anything. Your task is to complete the function countWays() which takes the string s1 and s2 as input parameters and returns the number of subsequences of s1 equal to s2.

Expected Time Complexity: O(n*m)  [n and m are lengths of the strings s1 and s2]
Expected Auxiliary Space: O(n*m)     [n and m are lengths of the strings s1 and s2]

Constraints:
1 ≤ n, m ≤ 500  [n and m are lengths of the strings s1 and s2]
*/

class Solution 
{
    public:
        int mod=1e9+7;
        int help(string a,string b,int i,int j,vector<vector<int>>&dp)
        {
          if(j==b.size())return 1;
          if(i==a.size())return 0;
          if(dp[i][j]!=-1)return dp[i][j];
          int x=0,y=0;
          if(a[i]==b[j])x=help(a,b,i+1,j+1,dp);
          y=help(a,b,i+1,j,dp);
          return dp[i][j]=+(x+y)%mod;
        }
        int countWays(string s1, string s2) 
        {
            vector<vector<int>>dp(s1.length(),vector<int>(s2.size(),-1));
            return help(s1,s2,0,0,dp);
        }
};
