

// Question Link :: "https://practice.geeksforgeeks.org/problems/mirror-tree/1"


// Solution //

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        rec(node);
    }
    
    void rec(Node *node){
        
        Node *temp;
        
        temp = node->left;
        node->left = node->right;
        node->right = temp;
        
        if( node->left != NULL )
            rec(node->left);
        
        if( node->right != NULL )
            rec(node->right);
        
    }
};
