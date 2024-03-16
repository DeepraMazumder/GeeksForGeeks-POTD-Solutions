/*
You are given a node del_node of a Singly Linked List where you have to delete a value of the given node from the linked list but you are not given the head of the list.

By deleting the node value, we do not mean removing it from memory. We mean:
1. The value of the given node should not exist in the linked list.
2. The number of nodes in the linked list should decrease by one.
3. All the values before & after the del_node node should be in the same order.

Note:
1. Multiple nodes can have the same values as the del_node, but you must only remove the node whose pointer del_node is given to you.
2. It is guaranteed that there exists a node with a value equal to the del_node value and it will not be the last node of the linked list.
Example 1:

Input: Linked List = 1 -> 2 del_node = 1

Output: 2

Explanation: After deleting 1 from the linked list, we have remaining nodes as 2.

Example 2:

Input: Linked List = 10 -> 20 -> 4 -> 30 del_node = 20

Output: 10 4 30

Explanation: After deleting 20 from the linked list, we have remaining nodes as 10, 4, 30.

Your Task:
You don't need to read or print anything. You only need to complete the function deleteNode() which takes a reference of the deleting node value & your task is to delete the given node value.

Expected Time Complexity: O(1).
Expected Auxilliary Space: O(1).

Constraints:
2 <= n <= 103  
1 <= elements of the linked list <= 109
*/

class Solution 
{
    public:
        void deleteNode(Node *del_node) 
        {
            if (del_node == nullptr) 
                return;
            if (del_node->next == nullptr) 
            {
                delete del_node; 
                del_node = nullptr; 
                return;
            }
            Node *temp = del_node->next;
            del_node->data = temp->data;
            del_node->next = temp->next;
            delete temp;
        }
};
