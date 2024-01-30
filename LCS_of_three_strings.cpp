/*
Given 3 strings A, B and C, the task is to find the length of the longest sub-sequence that is common in all the three given strings.

Example 1:

Input:
A = "geeks"
B = "geeksfor", 
C = "geeksforgeeks"

Output: 5

Explanation: "geeks"is the longest common subsequence with length 5.

Example 2:

Input: 
A = "abcd"
B = "efgh"
C = "ijkl"

Output: 0
 
Explanation: There's no subsequence common in all the three strings.

Your Task:
You don't need to read input or print anything. Your task is to complete the function LCSof3() which takes the strings A, B, C and their lengths n1, n2, n3 as input and returns the length of the longest common
subsequence in all the 3 strings.

Expected Time Complexity: O(n1*n2*n3).
Expected Auxiliary Space: O(n1*n2*n3).

Constraints:
1 <= n1, n2, n3 <= 20
Elements of the strings consitutes only of the lower case english alphabets.
*/

class Solution
{
    public:
        int recursion(string a, int n1, string b, int n2, string c, int n3, int i, int j, int k)
        {
            if (i >= n1 || j >= n2 || k >= n3)
            {
                return 0;
            }
            if (a[i] == b[j] && b[j] == c[k] && c[k] == a[i])
            {
                return (1 + recursion(a, n1, b, n2, c, n3, i+1, j+1, k+1));
            }
            int ans = max({recursion(a, n1, b, n2, c, n3, i+1, j, k), recursion(a, n1, b, n2, c, n3, i, j+1, k), recursion(a, n1, b, n2, c, n3, i, j, k+1)});
            return ans;
        }
        int Memo(string a, int n1, string b, int n2, string c, int n3, int i, int j, int k, vector<vector<vector<int>>> &dp)
        {
            if (i >= n1 || j >= n2 || k >= n3)
            {
                return 0;
            }
            if (dp[i][j][k] != -1)
            {
                return dp[i][j][k];
            }
            if (a[i] == b[j] && b[j] == c[k] && c[k] == a[i])
            {
                return (1 + Memo(a, n1, b, n2, c, n3, i+1, j+1, k+1, dp));
            }
            dp[i][j][k] = max({Memo(a, n1, b, n2, c, n3, i+1, j, k, dp), Memo(a, n1, b, n2, c, n3, i, j+1, k, dp), Memo(a, n1, b, n2, c, n3, i, j, k+1, dp)});
            return dp[i][j][k];
        }
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            vector<vector<vector<int>>> dp(n1+1, vector<vector<int>> (n2+1, vector<int> (n3+1, -1)));
            return Memo(A, n1, B, n2, C, n3, 0, 0, 0, dp);
        }
};
