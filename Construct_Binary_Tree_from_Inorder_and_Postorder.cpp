/*
Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays in[] and post[] respectively. The task is to construct a binary tree from these traversals.

Driver code will print the preorder traversal of the constructed tree.

Example 1:

Input:
n = 8
in[] = {4, 8, 2, 5, 1, 6, 3, 7}
post[] = {8, 4, 5, 2, 6, 7, 3, 1}

Output: 1 2 4 8 5 3 6 7

Explanation: 
For the given postorder and inorder traversal of tree the  resultant binary tree will be
          1
       /      \
     2        3
   /  \      /  \
  4   5    6   7
   \
    8
    
Example 2:

Input:
n = 5
in[] = {9, 5, 2, 3, 4}
post[] = {5, 9, 3, 4, 2}

Output: 2 9 5 4 3

Explanation:  
The  resultant binary tree will be
           2
        /     \
       9      4
        \     /
         5   3
         
Your Task:
You do not need to read input or print anything. Complete the function buildTree() which takes the inorder, postorder traversals and the number of nodes in the tree as input parameters and returns the root node
of the newly constructed Binary Tree.

Expected Time Complexity: O(n^2)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 10^3
1 <= in[i], post[i] <= 10^6
*/

class Solution
{
    public:
        void solve (Node **root , int ii , int ij ,int pi,int pj , int *po, map <int,int>&m)
        {
            int val = po[pj];
            int ind = m[val];
            int ci = ind-ii;
            *root = new Node (val);
            if (ind -1 >=ii)
                solve (&(*root)->left, ii, ind-1, pi, pi+ci-1 ,po,m );
            if (ind +1 <=ij)
                solve (&(*root)->right, ind+1, ij, pi+ci, pj-1 ,po,m );
        }
        Node *buildTree(int in[], int post[], int n) 
        {
            map <int,int>  m;
            for (int i=0;i<n;i++) m[in[i]]=i;
            Node * head =NULL;
            solve (&head , 0,n-1,0,n-1,post,m);
            return head;
        }
};
