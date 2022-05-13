

// Question Link :: "https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/"


// Solution //

class Solution {
public:
    Node* connect(Node* root) {
        
        if( root == NULL ) return root;
        
        queue<Node*> q;
        Node *previous;
        int tempSize;
        q.push(root);
        
        while( q.empty() == false ){
            
            tempSize = q.size();
            previous = NULL;
            while( tempSize ){
                
                auto node = q.front();
                q.pop();
                
                if( node->left != NULL ) q.push(node->left);
                if( node->right != NULL ) q.push(node->right);
                
                if( previous != NULL ) previous->next = node;
                previous = node;
                tempSize -= 1;
            }
        }
        return root;
    }
};