/*
You are given two linked lists that represent two large positive numbers. From the two numbers represented by the linked lists, subtract the smaller number from the larger one. Look at the examples to get a
better understanding of the task.

Example 1:

Input:
L1 = 1->0->0
L2 = 1->2

Output: 88

Explanation: First linked list represents 100 and the second one represents 12. 12 subtracted from 100 gives us 88 as the result. It is represented as 8->8 in the linked list.

Example 2:

Input:
L1 = 0->0->6->3
L2 = 7->1->0

Output: 647

Explanation: First linked list represents 0063 => 63 and the second one represents 710. 63 subtracted from 710 gives us 647 as the result. It is represented as 6->4->7 in the linked list.

Your Task:
You do not have to take any input or print anything. The task is to complete the function subLinkedList() that takes heads of two linked lists as input parameters and which should subtract the smaller number from
the larger one represented by the given linked lists and return the head of the linked list representing the result.

n and m are the length of the two linked lists respectively.
Expected Time Complexity:  O(n+m)
Expected Auxiliary Space: O(n+m)

Constraints:
1 <= n <= 10000
0 <= values represented by the linked lists < 10n
0 <= values represented by the linked lists < 10m
*/

class Solution 
{ 
    public: 
        string convertToString(Node* head) 
        { 
            string s = ""; 
            bool l = 0; 
            while(head) 
            { 
                if(head->data != 0) 
                    l = 1; 
                if(l) 
                    s += ('0' + head->data); 
                head = head->next; 
            } 
            return s; 
        } 
        Node* subLinkedList(Node* head1, Node* head2) 
        { 
            string s1 = convertToString(head1), s2 = convertToString(head2); 
            if(s1.size() < s2.size()) 
                swap(s1, s2); 
            else if((s1.size() == s2.size()) && s1 <= s2) 
                swap(s1, s2); 
            int n = s1.size(), m = s2.size(); 
            int carry = 0; 
            int j = m - 1; 
            for(int i = n - 1; i >= 0; i--) 
            { 
                int val = (s1[i] - '0') - carry - ((j >= 0) ? (s2[j] - '0') : 0); 
                if(val < 0) 
                { 
                    carry = 1; 
                    s1[i] = ('0' + 10 + val); 
                } 
                else 
                { 
                    carry = 0; 
                    s1[i] = ('0' + val); 
                } 
                j--; 
            } 
            int i = 0; 
            while(i < n && s1[i] == '0') 
                i++; 
            LinkedList* ans = new LinkedList(); 
            while(i < n) 
                ans->insert((s1[i++] - '0')); 
            if(ans->head == nullptr) 
                ans->insert(0); 
            return ans->head; 
        } 
};
