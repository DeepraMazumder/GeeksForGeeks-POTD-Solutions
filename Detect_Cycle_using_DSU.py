'''
Given an undirected graph with no self loops with V (from 0 to V-1) nodes and E edges, the task is to check if there is any cycle in the undirected graph.
Note: Solve the problem using disjoint set union (DSU).

Example 1:

Input: https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/701410/Web/Other/f496602b-dcfb-4de5-bdf6-0c51462af952_1685087018.png

Output: 1

Explanation: There is a cycle between 0->2->4->0

Example 2:

Input: https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/701410/Web/Other/ca19a9ca-7f9f-4c36-98cc-e678c1076ffd_1685087019.png

Output: 0

Explanation: The graph doesn't contain any cycle

Your Task:
You don't need to read or print anyhting. 
Your task is to complete the function detectCycle() which takes number of vertices in the graph denoting as V and adjacency list adj and returns 1 if graph contains any cycle otherwise returns 0.

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ 104
'''

class Solution:
    def detectCycle(self, V, adj):
        class dsu:
            def __init__(self,n):
                self.pr=[*range(n)]
                self.sz=[1]*n
            def fd(self,a):
                while self.pr[a]!=a:
                    a=self.pr[a]
                return a
            def un(self,a,b):
                a=self.fd(a)
                b=self.fd(b)
                if self.pr[a]==self.pr[b]:
                    return True
                if self.sz[a]>self.sz[b]:
                    a,b=b,a
                self.pr[a]=b
                self.sz[b]+=self.sz[a]
                return False
        nodes=dsu(V)
        for i,lst in enumerate(adj):
            for j in lst:
                if i>j:
                    continue
                if nodes.un(i,j):
                    return 1
        return 0
