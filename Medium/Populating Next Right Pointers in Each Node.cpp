

// Question Link :: "https://leetcode.com/problems/populating-next-right-pointers-in-each-node/"


// Solution //

class Solution {
public:
    
    vector<Node*> BFS(vector<Node*> nodes){
        
        vector<Node*> newNodes;
        for(auto np : nodes){
            if( np->left != NULL ) newNodes.push_back(np->left);
            if( np->right != NULL) newNodes.push_back(np->right);
        }
        return newNodes;
    }
    Node* connect(Node* root) {
        if( root==NULL ) return root;
        vector<Node*> nodes = {root};
        nodes = BFS(nodes);
        while(nodes.size()){
            for(int i=0;i<nodes.size()-1;i++)
                nodes[i]->next = nodes[i+1];
            nodes = BFS(nodes);
        }
        return root;
    }
};