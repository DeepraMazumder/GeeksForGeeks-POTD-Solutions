/*
Complete the Insert and Search functions for a Trie Data Structure. 

Insert: Accepts the Trie's root and a string, modifies the root in-place, and returns nothing.
Search: Takes the Trie's root and a string, returns true if the string is in the Trie, otherwise false.
Note: To test the correctness of your code, the code-judge will be inserting a list of N strings called into the Trie, and then will search for the string key in the Trie. The code-judge will generate 1 if the
key is present in the Trie, else 0.

Example 1:

Input:
n = 8
list[] = {the, a, there, answer, any, by, bye, their}
key = the

Output: 1

Explanation: "the" is present in the given set of strings. 

Example 2:

Input:
n = 8
list[] = {the, a, there, answer, any, by, bye, their}
key = geeks

Output: 0

Explanation: "geeks" is not present in the given set of strings.

Your Task:
You do not have to take any input or print anything. Complete insert and search functions. 

Expected Time Complexity: O(M+|key|)
Expected Auxiliary Space: O(M)
Here M = sum of the length of all strings which are present in the list[] 

Constraints:
1 <= N <= 104
1 <= length of list[i] <= 30
All strings will constitute of lowercase alphabets only.
*/

class Solution
{
    public:
        bool containsKey(char a,struct TrieNode *root)
        {
            return root->children[a-'a']!=NULL;
        }
        void put(char a,struct TrieNode *Node,struct TrieNode *root)
        {
            root->children[a-'a'] = Node;
        }
        TrieNode *get(char a,struct TrieNode *Node)
        {
            return Node->children[a-'a'];
        }
        void setEnd(struct TrieNode *Node)
        {
            Node->isLeaf = true;
        }
        void insert(struct TrieNode *root, string key)
        {
            for(int i = 0;i < key.length();i++)
            {
                if(!containsKey(key[i],root))
                {
                    put(key[i],new TrieNode(),root);
                }
                root = get(key[i],root);
            }
            setEnd(root);
        }
        bool search(struct TrieNode *root, string key) 
        {
            for(int i = 0;i < key.length();i++)
            {
                if(!containsKey(key[i],root))return false;
                root = get(key[i],root);
            }
            return root->isLeaf;
        }
};
