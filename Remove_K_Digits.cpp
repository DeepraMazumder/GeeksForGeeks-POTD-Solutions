/*
Given a non-negative integer S represented as a string, remove K digits from the number so that the new number is the smallest possible.
Note : The given num does not contain any leading zero.

Example 1:

Input: S = "149811", K = 3

Output: 111

Explanation: Remove the three digits 4, 9, and 8 to form the new number 111 which is smallest.

Example 2:

Input: S = "1002991", K = 3

Output: 21

Explanation: Remove the three digits 1(leading one), 9, and 9 to form the new number 21(Note that the output must not contain leading zeroes) which is the smallest.

Your Task:
You don't need to read input or print anything. Your task is to complete the function removeKdigits() which takes the string S and an integer K as input and returns the new number which is the smallest possible.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(|S|).

Constraints:
1<= K <= |S|<=106
*/

class Solution 
{
  public:
    string removeKdigits(string S, int k) 
    {
        int N = S.size() ;
        stack<char>st ;
        for(int i = 0 ; i < N ; i ++)
        {
            while(!st.empty() and k and st.top() > S[i]) st.pop() , k --;
            st.push(S[i]) ;
        }
        if(st.empty()) return "0" ;
        while(k--) st.pop() ;
        string ans ;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop() ;
        }
        reverse(begin(ans),end(ans)) ;
        int i = 0 ;
        while(ans[i] == '0') i ++;
        return (i == ans.size() ? "0" : ans.substr(i)) ;
    }
};
