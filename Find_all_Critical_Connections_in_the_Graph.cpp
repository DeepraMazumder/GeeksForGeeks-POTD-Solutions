/*
A critical connection refers to an edge that, upon removal, will make it impossible for certain nodes to reach each other through any path. You are given an undirected connected graph with v vertices and e edges
and each vertex distinct and ranges from 0 to v-1, and you have to find all critical connections in the graph. It is ensured that there is at least one such edge present.

Note: The answers may be presented in various potential orders. Each edge should be displayed in sorted order. For instance, if there's an edge between node 1 and node 2, it should be stored as (1,2) rather than
(2,1). Additionally, it is expected that you store the edges in sorted order.

Example 1:

Input: https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/706303/Web/Other/bbe726f7-e9f7-4a0c-b9fa-c649299d9784_1685087730.png

Output:
0 1
0 2

Explanation: On removing edge (0, 1), you will not be able to reach node 0 and 2 from node 1. Also, on removing edge (0, 2), you will not be able to reach node 0 and 1 from node 2.

Example 2:

Input: https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/706303/Web/Other/730505a5-24f6-41de-bd11-84a0a9e56d49_1685087731.png

Output: 2 3

Explanation: The edge between nodes 2 and 3 is the only Critical connection in the given graph.

Your task:
You dont need to read input or print anything. Your task is to complete the function criticalConnections() which takes the integer v denoting the number of vertices and an adjacency list adj as input parameters
and returns  a list of lists containing the Critical connections in the sorted order.

Expected Time Complexity: O(v + e)
Expected Auxiliary Space: O(v)

Constraints:
1 ≤ v, e ≤ 104
*/

class Solution 
{
    public:
        void dfs(int node, int parent, int &time, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<vector<int>> &result, vector<int> adj[]) 
        {
            disc[node] = low[node] = ++time;
            visited[node] = true;
            for (int neighbor : adj[node]) 
            {
                if (!visited[neighbor]) 
                {
                    dfs(neighbor, node, time, disc, low, visited, result, adj);
                    low[node] = min(low[node], low[neighbor]);
                    if (low[neighbor] > disc[node]) 
                    {
                        result.push_back({min(node, neighbor), max(node, neighbor)});
                    }
                }
                else if (neighbor != parent) 
                {
                    low[node] = min(low[node], disc[neighbor]);
                }
            }
        }
        vector<vector<int>> criticalConnections(int v, vector<int> adj[]) 
        {
            vector<int> disc(v, 0);  // discovery time
            vector<int> low(v, 0);   // lowest reachable node
            vector<bool> visited(v, false);
            vector<vector<int>> result;
            int time = 0;
            for (int i = 0; i < v; i++) 
            {
                if (!visited[i]) 
                {
                    dfs(i, -1, time, disc, low, visited, result, adj);
                }
            }
            sort(result.begin(), result.end());
            return result;
        }
};
