/*
Given two decimal numbers, num1 and num2, represented by linked lists of size n and m respectively. The task is to return a linked list that represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are
required to return the head of the linked list 2->1->5->null.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Example 1:

Input:
n = 2
num1 = 45 (4->5->null)
m = 3
num2 = 345 (3->4->5->null)

Output: 3->9->0->null  

Explanation: For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).

Example 2:

Input:
n = 4
num1 = 0063 (0->0->6->3->null)
m = 2
num2 = 07 (0->7->null)

Output: 7->0->null

Explanation: For the given two linked list (0 0 6 3) and (0 7), after adding the two linked list resultant linked list will be (7 0).

Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(n+m)
Expected Auxiliary Space: O(max(n,m)) for the resultant list.

Constraints:
1 <= n, m <= 10^4
*/

class Solution
{
    public:
        Node* reverse(struct Node *head)
        {
            if(head->next == NULL)
            {
                return head;
            }
            Node *forw = NULL;
            Node* current = head , *prev = NULL;
            while(current != NULL)
            {
                forw = current->next;
                current->next = prev;
                prev = current;
                current = forw;
            }
            return prev;
        }
        void insertAtTail(struct Node* &head, struct Node* &tail, int data)
        {
            Node* temp = new Node(data);
            if(head == NULL)
            {
                head = temp;
                tail = temp;
                return;
            }
            else
            {
                tail -> next = temp;
                tail = temp;
            }
        }
        struct Node* add(struct Node* first, struct Node* second) 
        {
            int carry = 0;
            Node* ansHead = NULL;
            Node* ansTail = NULL;
            while(first != NULL || second != NULL || carry != 0) 
            {
                int val1 = 0;
                if(first != NULL)
                    val1 = first -> data;
                int val2 = 0;
                if(second !=NULL)
                    val2 = second -> data;
                int sum = carry + val1 + val2;
                int digit = sum%10;
                insertAtTail(ansHead, ansTail, digit);
                carry = sum/10;
                if(first != NULL)
                    first = first -> next;
                if(second != NULL)
                    second = second -> next;
            }
            return ansHead;
        }
        struct Node* addTwoLists(struct Node* num1, struct Node* num2)
        {
            Node* first = reverse(num1);
            Node* second = reverse(num2);
            Node* ans = add(first , second);
            ans = reverse(ans);
            while(ans->next!=NULL and ans->data==0 )
            {
               ans=ans->next;
            }
            return ans;
        }
};
