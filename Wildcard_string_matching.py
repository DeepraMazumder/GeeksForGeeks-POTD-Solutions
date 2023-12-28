'''
Given two strings wild and pattern. Determine if the given two strings can be matched given that, wild string may contain * and ? but string pattern will not. * and ? can be converted to another character
according to the following rules:

* --> This character in string wild can be replaced by any sequence of characters, it can also be replaced by an empty string.
? --> This character in string wild can be replaced by any one character.

Example 1:

Input: 
wild = ge*ks
pattern = geeks

Output: Yes

Explanation: Replace the '*' in wild string with 'e' to obtain pattern "geeks".

Example 2:

Input: 
wild = ge?ks*
pattern = geeksforgeeks

Output: Yes

Explanation: Replace '?' and '*' in wild string with 'e' and 'forgeeks' respectively to obtain pattern "geeksforgeeks"

Your Task:
You don't need to read input or print anything. Your task is to complete the function match() which takes the string wild and pattern as input parameters and returns true if the string wild can be made equal to the string pattern, otherwise, returns false.

Expected Time Complexity: O(length of wild string * length of pattern string)
Expected Auxiliary Space: O(length of wild string * length of pattern string)

Constraints:
1 <= length of the two string <= 10^3
'''

class Solution:
    def recursion(self, wild, it1, len1, pattern, it2, len2):
        if it1 == len1 and it2 == len2:
            return True
        if it1 >= len1:
            return False
        if wild[it1] == '*':
            while it1 + 1 < len1 and wild[it1 + 1] == '*':
                it1 += 1
        if it1 >= len1:
            return False
        if it2 >= len2:
            if it1 == len1 - 1 and wild[len1 - 1] == '*':
                return True
            return False
        if wild[it1] == '*' and it1 + 1 != len1 and it2 == len2:
            return False
        if wild[it1] == '?' or wild[it1] == pattern[it2]:
            return self.recursion(wild, it1 + 1, len1, pattern, it2 + 1, len2)
        if wild[it1] == '*':
            return (self.recursion(wild, it1, len1, pattern, it2 + 1, len2) or 
                    self.recursion(wild, it1 + 1, len1, pattern, it2, len2))
        return False
    def match(self, wild, pattern):
        len1 = len(wild)
        len2 = len(pattern)
        flag = self.recursion(wild, 0, len1, pattern, 0, len2)
        return flag
