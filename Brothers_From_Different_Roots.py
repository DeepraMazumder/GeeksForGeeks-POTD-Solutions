'''
Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x, your task is to complete the function countPairs(), that returns the count of all pairs of (a, b), where a belongs to one BST and b belongs to another BST, such that a + b = x.

Example 1:

Input:
BST1:

       5
     /   \
    3     7
   / \   / \
  2   4 6   8
  
BST2:

       10
     /    \
    6      15
   / \    /  \
  3   8  11   18
  
x = 16

Output: 3

Explanation: The pairs are: (5, 11), (6, 10) and (8, 8)

Example 2:

Input:
BST1:

  1
   \
    3
   /
  2
  
BST2:

    3
   / \
  2   4
 /     
1

x = 4

Output: 3

Explanation: The pairs are: (2, 2), (3, 1) and (1, 3)

Your Task:
You don't need to read input or print anything. Your task is to complete the function countPairs(), which takes two BST's as parameter in the form of root1 and root2 and the integer x, 
that returns the count of all pairs from both the BSTs whose sum is equal to x.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 106
'''

class Solution:   
    def countPairs(self, root1, root2, target_sum):
        stack1, stack2 = [], []
        count = 0
        while True:
            while root1:
                stack1.append(root1)
                root1 = root1.left
            while root2:
                stack2.append(root2)
                root2 = root2.right
            if not stack1 or not stack2:
                break
            top1, top2 = stack1[-1], stack2[-1]
            if top1.data + top2.data == x:
                count += 1
                stack1.pop()
                stack2.pop()
                root1 = top1.right
                root2 = top2.left
            elif top1.data + top2.data < x:
                stack1.pop()
                root1 = top1.right
            else:
                stack2.pop()
                root2 = top2.left
        return count 
