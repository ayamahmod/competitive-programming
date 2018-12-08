/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
write a function to check whether these edges make up a valid tree.

Example
Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Notice
You can assume that no duplicate edges will appear in edges.
Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

class Solution {
public:
    void constructGraph(vector<vector<int> >& edges, vector<vector<int> >& graph) {
        for(int i = 0; i < edges.size(); ++i) {
            int e1 = edges[i][0];
            int e2 = edges[i][1];
            graph[e1].push_back(e2);
            graph[e2].push_back(e1);
        }
    }

    bool isValidTree(const vector<vector<int> >& graph) {
        vector<bool> visited(graph.size(), false);
        vector<int> parent(graph.size(), -1);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        parent[0] = 0;
        while(!q.empty()) {
            int nd = q.front();
            q.pop();
            for(int i = 0; i < graph[nd].size(); ++i) {
                int ne = graph[nd][i];
                if(!visited[ne]) {
                    q.push(ne);
                    parent[ne] = nd;
                    visited[ne] = true;
                }
                else if(ne != parent[nd]) return false;
            }
        }
        for(int i = 0; i < visited.size(); ++i)
            if(!visited[i])  return false;
        return true;
    }

    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        if(n == 0) return false;
        // write your code here
        vector<vector<int> > graph(n);
        constructGraph(edges, graph);
        return isValidTree(graph);
    }
};
