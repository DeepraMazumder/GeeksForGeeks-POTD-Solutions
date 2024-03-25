/*Given a positive integer n. Your task is to generate a string list of all n-bit binary numbers where, for any prefix of the number, there are more or an equal number of 1's than 0's. The numbers should be sorted
in decreasing order of magnitude.

Example 1:

Input: n = 2

Output: "11, 10"

Explanation: Valid numbers are those where each prefix has more 1s than 0s:
11: all its prefixes (1 and 11) have more 1s than 0s.
10: all its prefixes (1 and 10) have more 1s than 0s.
So, the output is "11, 10".

Example 2:

Input: n = 3

Output: "111, 110, 101"

Explanation: Valid numbers are those where each prefix has more 1s than 0s.
111: all its prefixes (1, 11, and 111) have more 1s than 0s.
110: all its prefixes (1, 11, and 110) have more 1s than 0s.
101: all its prefixes (1, 10, and 101) have more 1s than 0s.
So, the output is "111, 110, 101".

User Task:
Your task is to complete the function NBitBinary() which takes a single number as input n and returns the list of strings in decreasing order. You need not take any input or print anything.

Expected Time Complexity: O(|2n|)
Expected Auxiliary Space: O(2n)

Constraints:
1 <= n <= 15
*/

class Solution
{
    public:
        void solve(string str, int count0,int count1, vector<string>&ans,int n)
        {
            if(str.length() == n)
            {
                ans.push_back(str);
                return;
            }
            if(count1>count0)
            {
                solve(str+"1",count0,count1+1,ans,n);
                solve(str+'0',count0+1,count1,ans,n);
            }
            else
            {
                solve(str+"1",count0,count1+1,ans,n);
            }
        }
    
    	vector<string> NBitBinary(int n)
    	{
    	    vector<string>ans;
    	    string str = "";
    	    int count1 = 0;
    	    int count0 = 0;
    	    solve(str,count0,count1,ans,n);
    	    return ans;
    	}
};
