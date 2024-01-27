/*
Given an array p[] of length n used to denote the dimensions of a series of matrices such that the dimension of i'th matrix is p[i] * p[i+1]. There are a total of n-1 matrices. Find the most efficient way to
multiply these matrices together. As in MCM, you were returning the most effective count but this time return the string which is formed of A - Z (only Uppercase) denoting matrices & Brackets( "(" ")" ) denoting
multiplication symbols. For example, if n =11, the matrixes can be denoted as A - K as n<=26 & brackets as multiplication symbols.

NOTE:

Each multiplication is denoted by putting open & closed brackets to the matrices multiplied & also Please note that the order of matrix multiplication matters, as matrix multiplication is non-commutative A*B != 
B*A As there can be multiple possible answers, the console would print "True" for the correct string and "False" for the incorrect string. You need to only return a string that performs a minimum number of
multiplications.

Example 1:

Input: 
n = 5
p[] = {40, 20, 30, 10, 30}

Output: True

Explaination: Let's divide this into matrix (only 4 are possible) 
[ [40, 20] -> A
, [20, 30] -> B
, [30, 10] ->C
, [10, 30] -> D ]
First we perform multiplication of B & C -> (BC) then we multiply A to (BC) -> (A(BC)) then we multiply D to (A(BC)) -> ((A(BC))D) so the solution returned the string ((A(BC))D), which performs minimum
multiplications. The total number of multiplications are 20*30*10 + 40*20*10 + 40*10*30 = 26,000.

Example 2:

Input: 
n = 3
p = {3, 3, 3}

Output: True

Explaination: The solution returned the string (AB), which performs minimum multiplications. The total number of multiplications are (3*3*3) = 27.

Your Task:
You do not need to read input or print anything. Your task is to complete the function matrixChainOrder() which takes n and p[] as input parameters and returns the string of parenthesis for n-1 matrices. Use
uppercase alphabets to denote each matrix.

Expected Time Complexity: O(n3)
Expected Auxiliary Space: O(n2)

Constraints:
2 ≤ n ≤ 26 
1 ≤ p[i] ≤ 500 
*/

class Solution
{
    public:
        string matrixChainOrder(int p[], int n)
        {
            vector<vector<int>> dp(n, vector<int>(n, 0));
            vector<vector<int>> bracket(n, vector<int>(n, 0));
            for (int len = 2; len < n; len++) 
            {
                for (int i = 1; i < n - len + 1; i++) 
                {
                    int j = i + len - 1;
                    dp[i][j] = INT_MAX;
                    for (int k = i; k <= j - 1; k++) 
                    {
                        int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                        if (cost < dp[i][j]) 
                        {
                            dp[i][j] = cost;
                            bracket[i][j] = k;
                        }
                    }
                }
            }
            return printParenthesis(bracket, 1, n - 1);
        }
    private:
        string printParenthesis(const vector<vector<int>>& bracket, int i, int j) 
        {
            if (i == j) 
            {
                return string(1, 'A' + i - 1);
            }
            return "(" + printParenthesis(bracket, i, bracket[i][j]) +
                   printParenthesis(bracket, bracket[i][j] + 1, j) + ")";
        }
};
