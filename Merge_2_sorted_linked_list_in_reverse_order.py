'''
Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in non-increasing order.

Example 1:

Input:
N = 2, M = 2
list1 = 1->3
list2 = 2->4

Output: 4->3->2->1

Explanation: After merging the two lists in non-increasing order, we have new lists as 4->3->2->1.

Example 2:

Input:
N = 4, M = 3
list1 = 5->10->15->40 
list2 = 2->3->20

Output: 40->20->15->10->5->3->2

Explanation: After merging the two lists in non-increasing order, we have new lists as 40->20->15->10->5->3->2.

Your Task:
The task is to complete the function mergeResult() which takes reference to the heads of both linked list and returns the pointer to the merged linked list.

Expected Time Complexity : O(N+M)
Expected Auxiliary Space : O(1)

Constraints:
0 <= N, M <= 104
'''

class Solution:
    def mergeResult(self, h1, h2):
        def reverse(node):
            prev=None
            curr=node
            while curr:
                nxt=curr.next
                curr.next=prev
                prev=curr
                curr=nxt
            return prev
        prev1 = reverse(h1) if h1 else None
        prev2 = reverse(h2) if h2 else None
        curri,currj=prev1,prev2
        dummy = Node(-1)
        curr=dummy
        while curri and currj:
            if curri.data > currj.data:
                curr.next = Node(curri.data)
                curr=curr.next
                curri=curri.next
            else:
                curr.next = Node(currj.data)
                curr=curr.next
                currj=currj.next
        while curri:
            # print("this is not required")
            curr.next=Node(curri.data)
            curr=curr.next
            curri=curri.next
        while currj:
            # print("this is requried")
            curr.next=Node(currj.data)
            curr=curr.next
            currj=currj.next
        return dummy.next
