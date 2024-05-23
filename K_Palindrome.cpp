/*
Given a string str of length n, find if the string is K-Palindrome or not. A k-palindrome string transforms into a palindrome on removing at most k characters from it.


Example 1:

Input: str = "abcdecba"
n = 8, k = 1

Output: 1

Explaination: By removing 'd' or 'e' we can make it a palindrome.

Example 2:

Input: str = "abcdefcba"
n = 9, k = 1

Output: 0

Explaination: By removing a single character we cannot make it a palindrome.

Your Task:
You do not need to read input or print anything. Your task is to complete the function kPalindrome() which takes string str, n, and k as input parameters and returns 1 if str is a K-palindrome else returns 0.


Expected Time Complexity: O(n*n)
Expected Auxiliary Space: O(n*n)


Constraints:
1 ≤ n, k ≤ 10^3
*/

class Solution
{
    public:
        int kPalindrome(string s, int n, int k)
        {
                vector<int>curr(n+1,0),ahead(n+1,0);
                for(int x=n-1;x>=0;x--)
                {
                    for(int y=n-1;y>=0;y--) 
                        curr[y]= max({ahead[y],curr[y+1],(s[x]==s[n-y-1])?1+ahead[y+1]:0}); 
                        ahead=curr;
                }  
                return n-curr[0]<=k;
        }
};
