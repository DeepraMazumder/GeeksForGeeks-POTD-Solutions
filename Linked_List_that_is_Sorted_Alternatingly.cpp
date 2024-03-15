/*
You are given a Linked list of size n. The list is in alternating ascending and descending orders. Sort the given linked list in non-decreasing order.

Example 1:

Input:
n = 6
LinkedList = 1->9->2->8->3->7

Output: 1 2 3 7 8 9

Explanation: After sorting the given list will be 1->2->3->7->8->9.

Example 2:

Input:
n = 5
LinkedList = 13->99->21->80->50

Output: 13 21 50 80 99

Explanation: After sorting the given list will be 13->21->50->80->99.

Your Task:
You do not need to read input or print anything. The task is to complete the function sort() which should sort the linked list of size n in non-decreasing order. 

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= Number of nodes <= 100
0 <= Values of the elements in linked list <= 103
*/

class Solution
{
    public:
        void sort(Node **head)
        {
            for(Node* p=*head; p!= NULL ; p=p->next)
            {
                for(Node* q =p->next; q != NULL; q =q->next)
                {
                    if(p->data > q->data)
                    {
                        swap(p->data, q->data);
                    }
                }
            }
        }
};
