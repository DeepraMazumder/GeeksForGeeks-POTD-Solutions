/*
There is a standard numeric keypad on a mobile phone. You can only press the current button or buttons that are directly up, left, right, or down from it (for ex if you press 5, then pressing 2, 4, 6 & 8 are
allowed). Diagonal movements and pressing the bottom row corner buttons (* and #) are prohibited.

https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/704157/Web/Other/blobid0_1718345574.png

Given a number n, find the number of possible unique sequences of length n that you can create by pressing buttons. You can start from any digit.

Examples

Input: n = 1

Output: 10

Explanation: Number of possible numbers are 10 (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)  

Input: n = 2

Output: 36

Explanation: Possible numbers: 00, 08, 11, 12, 14, 22, 21, 23, 25 and so on. If we start with 0, valid numbers will be 00, 08 (count: 2). If we start with 1, valid numbers will be 11, 12, 14 (count: 3). If we 
start with 2, valid numbers  will be 22, 21, 23,25 (count: 4). If we start with 3, valid numbers will be 33, 32, 36 (count: 3). If we start with 4, valid numbers will be 44,41,45,47 (count: 4). If we start with 5,
valid numbers will be 55,54,52,56,58 (count: 5) and so on.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 25
*/

class Solution 
{
    public:
        long long dp[26][26][26];
        long long solve(int cnt, int i, int j, int n)
        {
            if(cnt == n) return 1;
            if(dp[cnt][i][j] != -1) return dp[cnt][i][j];
            int dr[] = {0,0,-1,1};
            int dc[] = {-1,1,0,0};
            long long ans = 0;
            ans += solve(cnt+1, i, j, n);
            for(int ind = 0; ind < 4; ind++)
            {
                int newi = i + dr[ind];
                int newj = j + dc[ind];
                if(newi <= 4 && newi >= 1 && newj <= 3 && newj >= 1 && !(newi == 4 && newj == 1) && !(newi == 4 && newj == 3))
                {
                    ans += solve(cnt + 1, newi, newj, n);
                }
            }
            return dp[cnt][i][j] = ans;
        }
        long long getCount(int n) 
        {
            memset(dp,-1,sizeof(dp));
            long long ans = 0;
            for(int i=1; i<=4; i++)
            {
                for(int j=1; j<=3; j++)
                {
                    if(i == 4 && j == 1) 
                        continue;
                    if(i == 4 && j == 3) 
                        continue;
                    ans += solve(1,i,j, n);
                }
            }
            return ans;
        }
};
