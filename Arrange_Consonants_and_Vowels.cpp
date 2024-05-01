/*
Given a singly linked list having n nodes containing english alphabets ('a'-'z'). Rearrange the linked list in such a way that all the vowels come before the consonants while maintaining the order of their arrival. 

Example 1:

Input:
n = 9
linked list: a -> b -> c -> d -> e -> f -> g -> h -> i 

Output: a -> e -> i -> b -> c -> d -> f -> g -> h

Explanation: After rearranging the input linked list according to the condition the resultant linked list will be as shown in output.

Example 2:

Input:
n = 8
linked list: a -> b -> a -> b -> d -> e -> e -> d 

Output: a -> a -> e -> e -> b -> b -> d -> d

Explanation: After rearranging the input linked list according to the condition the resultant linked list will be as shown in output.

Your Task:
Your task is to complete the function arrangeCV(), which takes head of linked list and arranges the list in such a way that all the vowels come before the consonants while maintaining the order of their arrival
and returns the head of the updated linked list.

Expected Time Complexity :  O(n)
Expected Auxiliary Space :  O(1)

Constraints:
1 <= n <= 10^4
'a' <= elements of linked list <= 'z'
*/

class Solution
{
    public:
        struct Node* arrangeCV(Node *head)
        {
    
            Node* node1=nullptr;
            Node* node2=nullptr;
            Node* head1=nullptr;
            Node* head2=nullptr;
            Node* curr=nullptr;
            Node* curr2=nullptr;
            Node* temp=head;
            while(temp)
            {
                
                if(temp->data=='a' ||temp->data=='e' ||temp->data=='i' ||temp->data=='o' ||temp->data=='u')
                {
                    node1=new Node(temp->data);
                    if(!head1)
                    {
                        head1=node1;
                    }
                    else
                    {
                        curr->next=node1; 
                    }
                    curr=node1;
                }
                else
                {
                    node2=new Node(temp->data);
                    if(!head2)
                    {
                        head2=node2;
                    }
                    else
                    {
                        curr2->next=node2; 
                    }
                    curr2=node2;
                }
                temp=temp->next;
            }
            if (!head1) 
            {
                return head2;
            }
            else
                temp=head1;
            while(temp->next)
            {
                temp=temp->next;
            }
            temp->next=head2;
            return head1;
        }
};
