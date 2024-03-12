/*
Consider the generalized Fibonacci number g, which is dependent on a, b and c as follows :-
g(1) = 1, g(2) = 1. For any other number n, g(n) = a*g(n-1) + b*g(n-2) + c.

For a given value of m, determine g(n)%m.

Example 1:

Input:
a = 3
b = 3
c = 3
n = 3
m = 5

Output: 4

Explanation: 
g(1) = 1 and g(2) = 1 
g(3) = 3*g(2) + 3*g(1) + 3 = 3*1 + 3*1 + 3 = 9
We need to return answer modulo 5, so 9%5 = 4, is the answer.

Example 2:

Input:
a = 2
b = 2
c = 2
n = 4
m = 100

Output: 16

Explanation:
g(1) = 1 and g(2) = 1
g(3) = 2*g(2) + 2*g(1) + 2 = 2*1 + 2*1 + 2 = 6
g(4) = 2*g(3) + 2*g(2) + 2  = 2*6 + 2*1 + 2 = 16
We need to return answer modulo 100, so 16%100 = 16, is the answer.

Your Task:
You don't need to read input or print anything. Your task is to complete the function genFibNum() which takes 5 Integers a, b, c, n, and m as input and returns g(n)%m.

Expected Time Complexity: O( log(n) ).
Expected Auxiliary Space: O(1).

Constraints:
1 <= a, b, c, n, m <= 109+7
*/

class Solution 
{
    public:
        vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B, long long m) 
        {
            int size = A.size();
            vector<vector<long long>> result(size, vector<long long>(size, 0));
            for (int i = 0; i < size; ++i) 
            {
                for (int j = 0; j < size; ++j) 
                {
                    for (int k = 0; k < size; ++k) 
                    {
                        result[i][j] += A[i][k] * B[k][j];
                        result[i][j] %= m;
                    }
                }
            }
            return result;
        }
        long long genFibNum(long long a, long long b, long long c, long long n, long long m) 
        {
            if (n <= 2)
                return 1LL % m;
            vector<vector<long long>> mat = {{a, b, 1}, {1, 0, 0}, {0, 0, 1}};
            vector<vector<long long>> res = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
            n -= 2;
            while (n > 0) 
            {
                if (n & 1)
                    res = multiply(res, mat, m);
                mat = multiply(mat, mat, m);
                n >>= 1;
            }
            return (res[0][0] + res[0][1] + c * res[0][2]) % m;
        }
};
