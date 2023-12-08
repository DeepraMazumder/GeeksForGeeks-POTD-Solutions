'''
Given an array of n integers. Find the minimum positive number to be inserted in array, so that sum of all elements of array becomes prime.

Example 1:

Input:
N=5
arr = {2, 4, 6, 8, 12}

Output: 5

Explanation: The sum of the array is 32 ,we can add 5 to this to make it 37 which is a prime number.

Example 2:

Input:
N=3
arr = {1, 5, 7}

Output:  0 

Explanation: The sum of the array is 13 which is already prime. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function minNumber() that takes array arr and integer N as input parameters and returns the minimum positive number to be inserted in the array so as to make it's sum a prime number.

Expected Time Complexity: O(N log(log N))
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 105
1 ≤ sum of all elements ≤ 106
'''

class Solution:
    def minNumber(self, arr,n):
        def isPrime(n):
            if n==2 or n==3:
                return True
            if n<=1 or n%2==0 or n%3==0:
                return False
            end=int(n**.5+1)
            for i in range(5,end,6):
                if n%i==0 or n%(i+2)==0:
                    return False
            return True
        s=sum(arr)
        p=s
        while not isPrime(p):
            p+=1
        return p-s
