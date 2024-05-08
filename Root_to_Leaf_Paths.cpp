/*
Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

Example 1:

Input:
       1
    /     \
   2       3
   
Output: 
1 2 
1 3 

Explanation: All possible paths:
1->2
1->3

Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60
    
Output: 
10 20 40 
10 20 60 
10 30 

Your Task:
Your task is to complete the function Paths() which takes the root node as an argument and returns all the possible paths. (All the paths are printed in new lines by the driver's code.)

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of the tree)

Constraints:
1<=n<=10^4
*/

class Solution 
{
    private:
        void solve(Node* root, vector<int> ds, vector<vector<int>> &ans)
        {
            if(!root)
                return;
            if(!root->left and !root->right)
            {
                ds.push_back(root->data);
                ans.push_back(ds);
                return;
            }
            ds.push_back(root->data);
            solve(root->left, ds, ans);
            solve(root->right, ds, ans);
        }
    public:
        vector<vector<int>> Paths(Node* root) 
        {
            vector<vector<int>> ans;
            vector<int> ds;
            solve(root, ds, ans);
            return ans;
        }
};
