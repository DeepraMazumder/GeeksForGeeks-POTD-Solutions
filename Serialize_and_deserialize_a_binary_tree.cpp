/*
Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

serialize() : stores the tree into an array a and returns the array.
deSerialize() : deserializes the array to the tree and returns the root of the tree.

Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver
code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).

Example 1:

Input:
      1
    /   \
   2     3
   
Output: 2 1 3

Example 2:

Input:
         10
       /    \
      20    30
    /   \
   40  60
   
Output: 40 20 60 10 30

Your Task:
The task is to complete two functions serialize which takes the root node of the tree as input and stores the tree into an array and deSerialize which deserializes the array to the original tree and returns the
root of it.

Expected Time Complexity: O(Number of nodes).
Expected Auxiliary Space: O(Number of nodes).

Constraints:
1 <= Number of nodes <= 10^4
1 <= Data of a node <= 10^9
*/

class Solution
{
    public:
        void dfs(Node* root, vector<int>& ans) 
        {
            if(!root)   return;
            dfs(root->left, ans);
            ans.push_back(root->data);
            dfs(root->right, ans);
        }
        int max (vector<int>& arr, int start, int end) 
        { 
            int i, max = arr[start], maxind = start; 
            for(i = start + 1; i <= end; i++) 
            { 
                if(arr[i] > max) 
                { 
                    max = arr[i]; 
                    maxind = i; 
                } 
            } 
            return maxind; 
        }
        vector<int> serialize(Node *root) 
        {
            vector<int> ans;
            dfs(root, ans);
            return ans;
        }
        Node* buildTree (vector<int>& inorder, int start, int end) 
        { 
            if (start > end) 
                return nullptr; 
            int i = max(inorder, start, end); 
            Node *root = new Node(inorder[i]); 
            if (start == end) 
                return root; 
            root->left = buildTree (inorder, start, i - 1); 
            root->right = buildTree (inorder, i + 1, end); 
            return root; 
        }
        Node * deSerialize(vector<int> &A) 
        {
           return buildTree(A, 0, A.size()-1);
        }
};
