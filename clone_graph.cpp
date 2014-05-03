/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    UndirectedGraphNode* deepCopy(UndirectedGraphNode *node,
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &mapping) {
        if (mapping.find(node) != mapping.end()) {
            return mapping[node];
        }

        UndirectedGraphNode *n = new UndirectedGraphNode(node->label);
        mapping[node] = n;
        for (int i = 0; i < node->neighbors.size(); i++) {
            n->neighbors.push_back(deepCopy(node->neighbors[i], mapping));
        }
        return n;
    }
public:
    // Time: O(n)
    // Space: O(n)
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mapping;
        return deepCopy(node, mapping);
    }
};
