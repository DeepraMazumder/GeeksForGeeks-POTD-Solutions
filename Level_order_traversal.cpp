/*
Given a root of a binary tree with n nodes, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.

Example 1:

Input:
    1
  /   \ 
 3     2
 
Output: 1 3 2

Example 2:

Input:
        10
     /      \
    20       30
  /   \
 40   60
 
Output: 10 20 30 40 60

Your Task:
You don't have to take any input. Complete the function levelOrder() that takes the root node as input parameter and returns a list of integers containing the level order traversal of the given Binary Tree.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 105
0 ≤ Data of a node ≤ 109
*/

class Solution
{
    public:
    vector<int> levelOrder(Node* root)
    {
        vector<int>v;
        queue<Node*>q;
        q.push(root);
        while(q.size()>0)
        {
            Node* curr=q.front();
            q.pop();
            v.push_back(curr->data);
            if(curr->left!=NULL)
            {
              q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
              q.push(curr->right);
            }
        }
        return v;
    }
};
