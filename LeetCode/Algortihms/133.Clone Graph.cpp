/*
Given the head of a graph, return a deep copy (clone) of the graph.
Each node in the graph contains a label (int) and a list (List[UndirectedGraphNode]) of its neighbors.
There is an edge between the given node and each of the nodes in its neighbors.
*/

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)   return NULL;
        unordered_map<int, UndirectedGraphNode*> p; // label, node
        queue<UndirectedGraphNode*> q;
        unordered_set<int> visited;
        q.push(node);
        visited.insert(node->label);
        UndirectedGraphNode* g2 = NULL;
        while(!q.empty()) {
            UndirectedGraphNode* nd1 = q.front();
            q.pop();
            UndirectedGraphNode* nd2;
            if(p.find(nd1->label) == p.end()) nd2 = new UndirectedGraphNode(nd1->label);
            else nd2 = p[nd1->label];
            p[nd2->label] = nd2;
            for(int i = 0; i < nd1->neighbors.size(); ++i) {
                int label = nd1->neighbors[i]->label;
                if(p.find(label) == p.end())
                    p[label] = new UndirectedGraphNode(label);
                nd2->neighbors.push_back(p[label]);
                if(visited.find(label) == visited.end()) {
                    q.push(nd1->neighbors[i]);
                    visited.insert(nd1->neighbors[i]->label);
                }
            }
            if(!g2) g2 = nd2;
        }
        return g2;
    }
};
