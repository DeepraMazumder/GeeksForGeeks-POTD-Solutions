/*
Consider Red lines of slope -1 passing between nodes (in following diagram). The diagonal sum in a binary tree is the sum of all node datas lying between these lines. Given a Binary Tree of size n, print all
diagonal sums.

For the following input tree, output should be 9, 19, 42.
9 is sum of 1, 3 and 5.
19 is sum of 2, 6, 4 and 7.
42 is sum of 9, 10, 11 and 12.

https://media.geeksforgeeks.org/wp-content/uploads/diagonal-sum-in-a-tree.jpg

Example 1:

Input:
         4
       /   \
      1     3
           /
          3
          
Output: 7 4 

Example 2:

Input:
           10
         /    \
        8      2
       / \    /
      3   5  2
      
Output: 12 15 3 

Your Task:
You don't need to take input. Just complete the function diagonalSum() that takes root node of the tree as parameter and returns an array containing the diagonal sums for every diagonal present in the tree with
slope -1.

Expected Time Complexity: O(nlogn).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 105
0 <= data of each node <= 104
*/

class Solution 
{
    public:
    void traverseTree(map<int,int>& mp, Node* node, int level)
    {
        if(!node)
        {
            return;
        }
        mp[level] += node->data;
        traverseTree(mp, node->left, level+1);
        traverseTree(mp, node->right, level);
    }
    public:
    vector<int> diagonalSum(Node* root) 
    {
        map<int, int> mp;
        traverseTree(mp, root, 0);
        vector<int> res;
        for(auto it : mp)
        {
            res.push_back(it.second);
        }
        return res;
    }
};
