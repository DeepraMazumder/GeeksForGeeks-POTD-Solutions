'''
Given a pair of strings of equal lengths, Geek wants to find the better string. The better string is the string having more number of distinct subsequences.
If both the strings have equal count of distinct subsequence then return str1.

Example 1:

Input:
str1 = "gfg", str2 = "ggg"

Output: "gfg"

Explanation: "gfg" have 6 distinct subsequences whereas "ggg" have 3 distinct subsequences. 

Example 2:

Input: str1 = "a", str2 = "b"

Output: "a"

Explanation: Both the strings have only 1 distinct subsequence. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function betterString() which takes str1 and str2 as input parameters and returns the better string.

Expected Time Complexity: O( max( str1.length, str2.length ) )
Expected Auxiliary Space: O( max( str1.length, str2.length ) )

Constraints:
1 <= str1.length , str2.length <= 30
'''

class Solution:
    def count_dist(self,s):
        dp=[0]*(len(s)+1)
        dp[0]=1
        last_occurence={}
        for i in range(1,len(s)+1):
            dp[i]=2*dp[i-1]
            if s[i-1] in last_occurence:
                dp[i]-=dp[last_occurence[s[i-1]]-1]
            
            last_occurence[s[i-1]]=i
        return dp[len(s)]

    def betterString(self, str1, str2):
        if self.count_dist(str1)>=self.count_dist(str2):
            return str1
        else:
            return str2
