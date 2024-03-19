/*
Given a weighted tree with n nodes and (n-1) edges. You are given q queries. Each query contains a number x. For each query, find the number of paths in which the maximum edge weight is less than or equal to x.

Note: Path from A to B and B to A are considered to be the same.

Example 1:

Input: 
n = 3
edges {start, end, weight} = {{1, 2, 1}, {2, 3, 4}}
q = 1
queries[] = {3}

Output: 1

Explanation: 
Query 1: Path from 1 to 2

Example 2:

Input: 
n = 7
edges {start, end, weight} = {{1, 2, 3}, {2, 3, 1}, {2, 4, 9}, {3, 6, 7}, {3, 5, 8}, {5, 7, 4}}
q = 3
queries[] = {1, 3, 5}

Output: 1 3 4

Explanation: 
Query 1: Path from 2 to 3
Query 2: Path from 1 to 2, 1 to 3, and 2 to 3
Query 3: Path from 1 to 2, 1 to 3, 2 to 3, and 5 to 7

Your Task:  
You don't need to read input or print anything. Complete the function maximumWeight()which takes integers n, list of edges where each edge is given by {start,end,weight}, an integer q and a list of q queries as
input parameters and returns a list of integers denoting the number of possible paths for each query. 

Expected Time Complexity: O(nlogn + qlogn)
Expected Auxiliary Space: O(n)

Constraints:
2 ≤ n ≤ 104
1 ≤ q ≤ 104
1 ≤ edges[i][0], edges[i][1] ≤ n
edges[i][0] != edges[i][1]
0 ≤ edges[i][2] ≤ 10^5
0 ≤ queries[i] ≤ 10^5
*/

class DisjointSet
{
    public:
        vector<int> parent, size;
        DisjointSet(int n)
        {
            parent.resize(n + 1);
            size.resize(n + 1);
            for (int i = 0; i <= n; i++)
            {
                parent[i] = i;
                size[i] = 1;
            }
        }
        int findUPar(int node)
        {
            if (node == parent[node])
                return node;
            return parent[node] = findUPar(parent[node]);
        }
        int unionBySize(int u, int v)
        {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            int ans = size[ulp_u] * size[ulp_v];
            if (ulp_u == ulp_v)
                return ans;
            if (size[ulp_u] < size[ulp_v])
            {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else
            {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
            return ans;
        }
};
class Solution
{
	public:
	vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
	{
	    for(int i = 0; i < n - 1; i++)
	    {
	        int u = edges[i][0];
	        int v = edges[i][1];
	        int wt = edges[i][2];
	        edges[i][0] = wt;
	        edges[i][1] = u;
	        edges[i][2] = v;
	    }
	    sort(edges.begin(), edges.end());
	    DisjointSet ds(n + 1);
	    map<int, int> mp;
	    int val = 0;
	    for(int i = 0; i < n - 1; i++)
	    {
	        int u = edges[i][1];
	        int v = edges[i][2];
	        int wt = edges[i][0];
	        mp[wt] = ds.unionBySize(u, v) + val;
	        val = mp[wt];
	    }
	    vector<int> ans(q, 0);
	    for(int i = 0; i < q; i++)
	    {
	        auto it = mp.upper_bound(queries[i]);
	        if(it != mp.begin())
	        {
	            it--;
	            ans[i] = it->second;
	        }
	    }
	    return ans;
	}
};
