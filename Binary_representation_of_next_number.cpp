/*
Given a binary representation in the form of a string(s) of a number n, the task is to find a binary representation of n+1.

Example 1:

Input: s = "10"

Output: 11

Explanation: "10" is the binary representation of 2 and binary representation of 3 is "11"

Example 2:

Input: s = "111"

Output: 1000

Explanation: "111" is the binary representation of 7 and binary representation of 8 is "1000"

Your Task: You don't need to read input or print anything. Complete the function binaryNextNumber()which takes s as input parameter and returns the string.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n) to store resultant string  

Constraints:
1 <= n <= 10^5
*/

class Solution 
{
    public:
        string binaryNextNumber(string s) 
        {
            int i, l = s.size();
            string ans = "";
            for (i = l - 1; i >= 0; i--) 
            {
                if (s[i] == '1')
                    s[i] = '0';
                else 
                {
                    s[i] = '1';
                    break;
                }
            }
            if (i < 0) 
            {
                ans += '1';
                i = 0;
            } 
            else 
            {
                i = 0;
                while (s[i] == '0')
                    i++;
            }
            ans += s.substr(i, l);
            return ans;
        }
};
