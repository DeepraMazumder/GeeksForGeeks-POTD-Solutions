/*
Given a binary search tree having n (n>1) nodes, the task is to find the minimum absolute difference between any two nodes.

Example 1:

Input: https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/712351/Web/Other/blobid0_1709057446.png

Output: 10

Explanation: There are no two nodes whose absolute difference is smaller than 10.

Example 2:

Input: https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/712351/Web/Other/blobid2_1709058082.png

Output: 20

Explanation: There are no two nodes whose absolute difference is smaller than 20.

Your Task:
You don't have to take any input. Just complete the function absolute_diff() , that takes root as input and return minimum absolute difference between any two nodes.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(Height of tree)

Constraints:
2 <= n <= 10^5
1 <= Node->data <= 10^9
*/

class Solution
{
    public:
        void inorder(Node *node, Node *&prev, int &minDiff)
        {
            if (node == nullptr)
                return;
            inorder(node->left, prev, minDiff);
            if (prev != nullptr)
            {
                minDiff = min(minDiff, node->data - prev->data);
            }
            prev = node;
            inorder(node->right, prev, minDiff);
        }
        int absolute_diff(Node *root)
        {
            int minDiff = INT_MAX;
            Node *prev = nullptr;
            inorder(root, prev, minDiff);
            return minDiff;
        }
};
