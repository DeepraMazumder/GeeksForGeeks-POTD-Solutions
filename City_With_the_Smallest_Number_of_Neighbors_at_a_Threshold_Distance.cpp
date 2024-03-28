/*
There are n cities labeled from 0 to n-1 with m edges connecting them. Given the array edges where edges[i] = [fromi , toi ,weighti]  represents a bidirectional and weighted edge between cities fromi and toi, and
given the integer distanceThreshold. You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance. If there are multiple
such cities, our answer will be the city with the greatest label.

Note: The distance of a path connecting cities i and j is equal to the sum of the edge's weights along that path.

Example 1:

Input:
n = 4, m = 4
edges = [[0, 1, 3],
         [1, 2, 1], 
         [1, 3, 4],  
         [2, 3, 1]]
distanceThreshold = 4

Output: 3

Explaination: https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/711146/Web/Other/db9aa4c2-8a65-4b18-b6ad-7034096be600_1684840736.png

The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.

Example 2:

Input: 
n = 5, m = 6
edges = [[0, 1, 2],
         [0, 4, 8],
         [1, 2, 3], 
         [1, 4, 2], 
         [2, 3, 1],
         [3, 4, 1]]
distanceThreshold = 2.

Output: 0

Explaination: https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/711146/Web/Other/blobid0_1709737447.png

The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findCity( ) which takes a number of nodes n, total number of edges m and vector of edges and distanceThreshold. and return
the city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance. If there are multiple such cities, return the city with the greatest label.

Expected Time Complexity: O(n^2 + length(edges)*nlog(n) )
Expected Auxiliary Space:  O(n^3)

Constraints:
1  ≤  n ≤  100
1 <= m <= n*(n-1)/2
length(edges[i]) == 3
0 <= fromi < toi < n
1 <= weighti distanceThreshold <= 10^4
All pairs (fromi, toi) are distinct
*/

class Solution 
{
    public:
        void dijsktra(int node, vector<pair<int,int>> adj[], vector<int> &dist) 
        {
            dist[node] = 0;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            pq.push({0, node});
            while(pq.empty() == false)
            {
                int cost = pq.top().first, node = pq.top().second;
                pq.pop();
                if(dist[node] < cost) continue;
                for(auto &it : adj[node]) 
                {
                    int nei = it.first, wt = it.second;
                    if(dist[nei] > cost + wt) 
                    {
                        dist[nei] = cost + wt;
                        pq.push({dist[nei], nei});
                    }
                }
            }
        }
        int findCity(int n, int m, vector<vector<int>>& edges, int thres) 
        {
            vector<pair<int,int>> adj[n];
            for(int i = 0 ; i < m ; i++) 
            {
                int u = edges[i][0], v = edges[i][1], cost = edges[i][2];
                adj[u].push_back({v, cost});
                adj[v].push_back({u, cost});
            }
            int mini = 1e5, ans = -1;
            for(int i = 0; i < n ; i++) 
            {
                vector<int> dist(n,1e9);
                dijsktra(i, adj, dist);
                int cnt = 0;
                for(int j = 0; j < n ; j++) 
                {
                    if(dist[j] <= thres) cnt++;
                }
                if(mini > cnt ) 
                {
                    mini = cnt, ans = i;
                }
                else if(mini == cnt) ans = i;
            }
            return ans;
        }
};
