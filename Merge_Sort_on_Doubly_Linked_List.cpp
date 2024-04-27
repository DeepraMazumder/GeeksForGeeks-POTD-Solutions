/*
Given Pointer/Reference to the head of a doubly linked list of n nodes, the task is to Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing order.

Example 1:

Input:
n = 8
value[] = {7,3,5,2,6,4,1,8}

Output:
1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1

Explanation: After sorting the given linked list in both ways, resultant matrix will be as given in the first two line of output, where first line is the output for non-decreasing order and next line is for non-
increasing order.

Example 2:

Input:
n = 5
value[] = {9,15,0,-1,0}

Output:
-1 0 0 9 15
15 9 0 0 -1

Explanation: After sorting the given linked list in both ways, the resultant list will be -1 0 0 9 15 in non-decreasing order and 15 9 0 0 -1 in non-increasing order.

Your Task:
The task is to complete the function sortDoubly() which takes reference to the head of the doubly linked and Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing. The
printing is done automatically by the driver code.

Expected Time Complexity: O(nlogn)
Expected Space Complexity: O(logn)

Constraints:
1 <= n <= 10^4
0 <= values[i] <= 10^5
*/

class Solution 
{
    public:
        Node* findMid(Node* head) 
        {
            Node *slow = head;
            Node *fast = head;
            while(fast->next && fast->next->next) 
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        }
        Node* merge(Node* left, Node* right) 
        {
            if(!left) return right;
            if(!right) return left;
            Node *cur = NULL, *res = NULL;
            if(left->data <= right->data) 
            {
                cur = res = left;
                left = left->next;
            } 
            else 
            {
                cur = res = right;
                right = right->next;
            }
            while(left && right) 
            {
                if(left->data < right->data) 
                {
                    cur->next = left;
                    left->prev = cur;
                    cur = left;
                    left = left->next; 
                }
                else 
                {
                    cur->next = right;
                    right->prev = cur;
                    cur = right;
                    right = right->next; 
                }
            }
            if(left) 
            {
                cur->next = left;
                left->prev = cur;
            }
            if(right) 
            {
                cur->next = right;
                right->prev = cur;
            }
            return res;
        }
        Node* sortDoubly(Node* head) 
        {
            if(head == nullptr || head->next == nullptr) 
            {
                return head;
            }
            Node* middle = findMid(head);
            Node* first = head;
            Node* second = middle->next;
            middle->next = second->prev = NULL;
            first = sortDoubly(first);
            second = sortDoubly(second);
            return merge(first, second);
        }
};
