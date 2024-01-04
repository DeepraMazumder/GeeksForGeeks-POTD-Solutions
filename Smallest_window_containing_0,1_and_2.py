'''
Given a string S consisting of the characters 0, 1 and 2. Your task is to find the length of the smallest substring of string S that contains all the three characters 0, 1 and 2. If no such substring exists, then 
return -1.

Example 1:

Input: S = 01212

Output: 3

Explanation: The substring 012 is the smallest substring that contains the characters 0, 1 and 2.

Example 2:

Input: S = 12121

Output: -1

Explanation: As the character 0 is not present in the string S, therefor no substring containing all the three characters 0, 1 and 2 exists. Hence, the answer is -1 in this case.

Your Task:
Complete the function smallestSubstring() which takes the string S as input, and returns the length of the smallest substring of string S that contains all the three characters 0, 1 and 2.

Expected Time Complexity: O( length( S ) )
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ length( S ) ≤ 105
All the characters of String S lies in the set {'0', '1', '2'}
'''

class Solution:
    def smallestSubstring(self, s):
        ans=float('inf')
        if len(set(s))<=2:
            return -1
        zero,one,two=-1,-1,-1
        for i in range(len(s)):
            if s[i]=='0':
                zero=i
            elif s[i]=='1':
                one=i
            else:
                two=i
            if one!=-1 and two!=-1 and zero!=-1:
                mx=max([zero,one,two])
                mn=min([zero,one,two])
                ans=min(ans,mx-mn+1)
        if ans!=float('inf'):
            return ans
        else:
            return -1
