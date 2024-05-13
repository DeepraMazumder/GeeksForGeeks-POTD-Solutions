/*
Given an undirected graph with v vertices(numbered from 1 to v) and e edges. Find the number of good components in the graph.
A component of the graph is good if and only if the component is fully connected.
Note: A fully connected component is a subgraph of a given graph such that there's an edge between every pair of vertices in the component, the given graph can be a disconnected graph. 

Example 1:

Input: https://media.geeksforgeeks.org/img-practice/good_comp_1-1656905170.png

e=3 
v=3
edges={{1, 2},{1, 3},{3, 2}}

Output: 1

Explanation: We can see that there is only one component in the graph and in this component there is a edge between any two vertces.

Example 2:

Input: https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/713974/Web/Other/0b0c03cb-9f66-4c94-8900-8120a171f9a3_1685087973.png

e=5 
v=7
edges={{1, 2},{7, 2},{3, 5},{3, 4},{4, 5}}

Output: 2

Explanation: We can see that there are 3 components in the graph. For 1-2-7 there is no edge between 1 to 7, so it is not a fully connected component. Rest 2 are individually fully connected component.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findNumberOfGoodComponent(), which takes an integer e and v and edges[][] as input parameters and returns an integer denoting
the number of good components.

Expected Time Complexity: O(v+e)
Expected Auxiliary Space: O(depth of the graph)

Constraints:
1 ≤ v, e ≤ 10^4
*/

class Solution 
{
    public:
        void dfs (unordered_map<int,vector<int>>&adj, int i, vector<int>&vis, vector<int>&temp)
        {
            temp.push_back(i);
            vis[i]++;
            for (auto it:adj[i])
            {
                if (!vis[it])
                    dfs(adj,it,vis,temp);
            }
        }
        int find(int v,unordered_map<int,vector<int>>&adj)
        {
            vector<int>vis(v+1,0);
                int ans = 0;
                for (int i=1; i<=v; i++)
                {
                    if (!vis[i])
                    {
                        vector <int> temp;
                        dfs(adj,i,vis, temp);
                        bool flag = true;
                        for (int i=0; i<temp.size(); i++)
                        {
                            if (adj[temp[i]].size()<temp.size()-1)
                            {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                            ans++;
                    }
                }
                return ans;
        }
        int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) 
        {
            unordered_map<int,vector<int>>adj;
            for(auto it:edges)
            {
                int u= it[0];
                int v= it[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            return find(v,adj);
        }
};
