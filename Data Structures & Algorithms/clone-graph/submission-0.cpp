/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> um;
        return clone(node, um);
    }

    Node* clone(Node* node, unordered_map<Node*, Node*> &um) {
        if(!node) return nullptr;
        if(um.find(node) != um.end()) return um[node];

        Node* newNode = new Node{};
        um[node] = newNode;
        newNode->val = node->val;

        for(auto n : node->neighbors) {
            newNode->neighbors.push_back(clone(n, um));
        }

        return newNode;
    }
};
