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
    vector<Node*> nodeReg;

    void dfs(Node* clone,Node* node){
        for(Node* next : node->neighbors){
            int next_val=next->val;
            if(nodeReg[next_val]==NULL){//create a new Node
                Node* new_neighbor=new Node(next_val);
                nodeReg[next_val]=new_neighbor;
                clone->neighbors.push_back(new_neighbor);
                dfs(new_neighbor,next);
            }
            else{//node already created search in nodeReg
                clone->neighbors.push_back(nodeReg[next_val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* clone=new Node(node->val);
        nodeReg.resize(110,NULL);
        nodeReg[node->val]=clone;
        dfs(clone,node);
        return clone;

    }
};