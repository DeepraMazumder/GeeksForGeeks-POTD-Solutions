/*
Eulerian Path is a path in a graph that visits every edge exactly once. Eulerian Circuit is an Eulerian Path that starts and ends on the same vertex. Given the number of vertices v and adjacency list adj denoting
the graph. Find that there exists the Euler circuit or not. Return 1 if there exist  alteast one eulerian path else 0.

Example 1:

Input: https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700536/Web/Other/b21c49fc-2edf-4662-b105-85f7bb2f7f30_1685086713.png
v = 4 
edges[] = {{0, 1}, 
           {0, 2}, 
           {1, 3}, 
           {2, 3}}

Output: 1

Explanation: corresponding adjacency list will be {{1, 2},{0, 3},{0, 3},{1, 2}} One of the Eularian circuit starting from vertex 0 is as follows: 0->1->3->2->0

Example 2:

Input: https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700536/Web/Other/blobid0_1709738992.png
v = 3
edges[] = {{0, 1}, 
         {0, 2}}         

Output: 0

Explanation: Corresponding adjacency list will be {{1, 2}} No Eulerian path is found.

Your Task:
You don't need to read or print anything. Your task is to complete the function isEularCircuitExist() which takes v and adjacency list adj[] as input parameter and returns boolean value 1 if Eular circuit exists
otherwise returns 0.

Expected Time Complexity: O(v + e)
Expected Space Complexity: O(v)

Constraints:
1 <= v <= 10^5
1 <= edges <= 2*10^5
*/

class Solution 
{
    public:
    	bool isEularCircuitExist(int v, vector<int>adj[])
    	{
            for(int i=0;i<v;i++)
            {
                if(adj[i].size()%2==1)
                return 0;
            }
            return 1;
    	}
};
