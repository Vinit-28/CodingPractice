

// Question Link :: "https://leetcode.com/problems/clone-graph/"


// Solution //

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if( node == NULL ) return NULL;
        
        int hashVal[101] = {0};
        Node *hashNode[101];
        
        return completeGraph(node, hashVal, hashNode);
    }
    
    Node* completeGraph(Node *originalGraphNode, int hashVal[], Node *hashNode[]){
        
        Node *dupNode = new Node(originalGraphNode->val);
        hashVal[dupNode->val]=1, hashNode[dupNode->val] = dupNode;
        
        for(auto n : originalGraphNode->neighbors){
            
            if( ! hashVal[n->val] ){
                Node *node = completeGraph(n, hashVal, hashNode);
                dupNode->neighbors.push_back(node);
            }
            else{
                dupNode->neighbors.push_back(hashNode[n->val]);
            }
        }
        return dupNode;
    }
    
    
};