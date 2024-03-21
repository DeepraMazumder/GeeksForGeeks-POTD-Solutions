/*
Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.

Example 1:

Input:
        1
      /   \
     2    3
    / \    /   \
   4   5 6   7
   
Output: 1 3 2 4 5 6 7

Example 2:

Input:
           7
        /     \
       9      7
     /  \      /   
    8   8  6     
   /  \
  10  9 
  
Output: 7 7 9 8 8 6 9 10 

Your Task:
You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as
they appear in the zig-zag level-order traversal of the tree.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 105
*/

class Solution
{
    public:
    vector <int> zigZagTraversal(Node* root)
    {
	      queue<Node*>q;
        vector<int>v;
        q.push(root);
        bool flag=false;
        while(!q.empty())
        {
            int n=q.size();
            int siz=v.size();
            while(n--)
            {
                Node*curr=q.front();
                q.pop();
                v.push_back(curr->data);
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            if(flag)
            {
                reverse(v.begin()+siz,v.end());
            }
            flag=!flag;
        }
        return v;
    }
};
