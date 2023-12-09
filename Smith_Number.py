'''
Given a number n, the task is to find out whether this number is a Smith number or not. A Smith number is a composite number whose sum of digits is equal to the sum of digits of its prime factors.

Example 1:

Input: n = 4

Output: 1

Explanation: The sum of the digits of 4 is 4, and the sum of the digits of its prime factors is 2 + 2 = 4.

Example 2:

Input: n = 378

Output: 1

Explanation: 378 = 21*33*71 is a Smith number since 3+7+8 = 2*1+3*3+7*1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function smithNum() which takes an Integer n as input and returns the answer.

Expected Time Complexity: O(n * log(n))
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 105
'''

class Solution:
    def smithNum(self, n):
        if self.isPrime(n): return 0
        ss = self.sumDigits(n)
        currSum = 0
        i = 2
        while i <= n and n > 1:
            if self.isPrime(i) == True:
                d = self.sumDigits(i)
                while n % i == 0:
                    currSum += d
                    n //= i
            i += 1
        return 1 if ss == currSum else 0
    def isPrime(self, n):
        i = 2
        while i * i <= n:
            if n % i == 0: return False
            i += 1
        return n > 1
    def sumDigits(self, n):
        ss = 0
        while n > 0:
            ss += n % 10
            n //= 10
        return ss
