/*
Given a singly linked list having n nodes, your task is to remove every kth node from the linked list. 

Example 1:

Input:
n = 8
linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 
k = 2

Output: 1 -> 3 -> 5 -> 7

Explanation: After removing every 2nd node of the linked list, the resultant linked list will be: 1 -> 3 -> 5 -> 7.

Example 2:

Input:
n = 10
linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 
k = 3

Output: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10

Explanation: After removing every 3rd node of the linked list, the resultant linked list will be: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10.

Your Task:
The task is to complete the function deleteK() which takes head of linked list and integer k as input parameters and delete every kth node from the linked list and return its head.

Expected Time Complexity :  O(n)
Expected Auxiliary Space :  O(1)

Constraints:
1 <= n <= 10^5
-10^9 <= elements of linked list <= 10^9
1 <= k <= n
*/

class Solution 
{
    public:
    Node* deleteK(Node *head,int k)
    {
        if(k == 1)
            return NULL;
        int count = 1;
        Node* temp = head;
        while(temp && temp->next)
        {
            if(count+1 == k)
            {
                temp->next = temp->next->next;
                count = 0;
            }
            count += 1;
            temp = temp->next;
        }
        return head;
    }
};
