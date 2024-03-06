/*
Given two strings, one is a text string and other is a pattern string. The task is to print the indexes of all the occurences of pattern string in the text string. For printing, Starting Index of a string should
be taken as 1. The strings will only contain lowercase English alphabets ('a' to 'z').

Example 1:

Input: 
text = "birthdayboy"
pattern = "birth"

Output: [1]

Explanation: The string "birth" occurs at index 1 in text.

Example 2:

Input:
text = "geeksforgeeks"
pattern = "geek"

Output: [1, 9]

Explanation: The string "geek" occurs twice in text, one starts are index 1 and the other at index 9.

Your Task:
You don't need to read input or print anything. Your task is to complete the function search() which takes the string text and the string pattern as input and returns an array denoting the start indices (1-based)
of substring pattern in the string text. 

Expected Time Complexity: O(|text| + |pattern|).
Expected Auxiliary Space: O(1).

Constraints:
1<=|text|<=5*105
1<=|pattern|<=|text|
*/

class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int>res;
            int q=101;
            int d=26;
            int M=pat.size();
            int N=txt.size();
            int p=0;
            int t=0;
            int h=1;
            for(int i=0;i<M-1;i++)
            {
                h=(h*d)%q;
            }
            for(int i=0;i<M;i++)
            {
                p=(d*p+pat[i])%q;
                t=(d*t+txt[i])%q;
            }
            for(int i=0;i<=N-M;i++)
            {
                if(p==t)
                {
                    int j=0;
                    for(j=0;j<M;j++)
                    {
                        if(txt[i+j]!=pat[j])
                        {
                            break;
                        }
                    }
                    if(j==M)
                    {
                        res.push_back(i+1);
                    }
                    
                }
                if(i<N-M)
                {
                    t=(d*(t-txt[i]*h)+txt[i+M])%q;
                    if(t<0)
                    {
                        t=t+q;
                    }
                }
            }
            return res;
        }
};
