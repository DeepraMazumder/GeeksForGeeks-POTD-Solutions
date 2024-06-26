/*
Given a square matrix a of size n x n, where each cell can be either 'X' or 'O', you need to find the size of the largest square subgrid that is completely surrounded by 'X'. More formally you need to find the
largest square within the grid where all its border cells are 'X'.

Example 1:

Input:
n = 2
a = [[X,X],
     [X,X]]
     
Output: 2

Explanation: The largest square submatrix surrounded by X is the whole input matrix.

Example 2:

Input:
n = 4
a = [[X,X,X,O],
     [X,O,X,X],
     [X,X,X,O],
     [X,O,X,X]]
     
Output: 3

Explanation: Here,the input represents following matrix of size 4 x 4
X X X O
X O X X
X X X O
X O X X
The square submatrix starting at (0,0) and ending at (2,2) is the largest submatrix surrounded by X. Therefore, size of that matrix would be 3.

Your Task:
You don't need to read input or print anything. Your task is to complete the function largestSubsquare() which takes the integer n and the matrix a as input parameters and returns the size of the largest
subsquare surrounded by 'X'.

Expected Time Complexity: O(n2)
Expected Auxillary Space: O(n2)

Constraints:
1 <= n <= 1000
a[i][j] belongs to {'X','O'}
*/

class Solution 
{
  public:
    int largestSubsquare(int n, vector<vector<char>> a) 
    {
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>> (n, {0, 0}));
        for(int i = 0; i < n; i++) 
        {
            int x = 0;
            for(int j = 0; j < n; j++) 
            {
                if(a[i][j] == 'X')
                    x++;
                else 
                    x = 0;
                dp[i][j].first = x;
            }
        }
        for(int i = 0; i < n; i++) 
        {
            int x = 0;
            for(int j = 0; j < n; j++) 
            {
                if(a[j][i] == 'X')
                    x++;
                else
                    x = 0;
                dp[j][i].second = x;
            }
        }
        int maxi = 0;
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                int mini = min(dp[i][j].first, dp[i][j].second);
                while(mini > 0) 
                {
                    int x = j - mini + 1, y = i - mini + 1;
                    if(x >= 0 and x < n and y >= 0 and y < n) 
                    {
                        if(dp[i][x].second >= mini and dp[y][j].first >= mini) 
                        {
                            maxi = max(maxi, mini); 
                            break;
                        }
                    }
                    mini--;
                }
            }
        }
        return maxi;
    }
};
