/*
Given a BST with n (n>=2) nodes, find the kth common ancestor of nodes x and y in the given tree. Return -1 if kth ancestor does not exist.

Nodes x and y will always be present in the input of a BST, and x != y.

Example 1:

Input: https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/861885/Web/Other/blobid0_1712119495.png

k = 2, x = 40, y = 60 

Output: 30

Explanation: Their 2nd common ancestor is 30.

Example 2:

Input: https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/861885/Web/Other/blobid1_1712119495.png

k = 2, x = 40, y = 60

Output: -1

Explanation: LCA of 40 and 60 is 50, which is root itself. There does not exists 2nd common ancestor in this case.

Your task :
You don't have to read input or print anything. Your task is to complete the function kthCommonAncestor() that takes the root of the tree, k, x and y as input and returns the kth common ancestor of x and y.
 
Expected Time Complexity: O(Height of the Tree)
Expected Space Complexity: O(Height of the Tree)
 
Your Task :
1 <= n, k <= 10^5
1 <= node->data, x, y <= 10^9
*/

class Solution
{
    public:
        void solve(Node *root, int x, int y, vector<int> &v) 
        {
            if(!root)
                return;
            v.push_back(root->data);
            if(x < root->data and y < root->data)
                solve(root->left, x, y, v);
            if(x > root->data and y > root->data)
                solve(root->right, x, y, v);
        }
        int kthCommonAncestor(Node *root, int k, int x, int y)
        { 
            vector<int> ancs;
            solve(root, x, y, ancs);
            reverse(ancs.begin(), ancs.end());
            return k > ancs.size() ? -1 : ancs[k - 1];
        }
};
