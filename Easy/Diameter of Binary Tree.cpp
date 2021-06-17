

// Question Link :: "https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1"



// Solution //

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    
    int max_height, max_dia=0;
    int diameter(Node* root) {
        // Your code here
        max_dia = 0;
        rec(root);
        
        if( max_dia > 0 )
            return max_dia;
        
        max_height = 0;
        
        if(root->left!=NULL){
            get_height(root->left,1);
        }
        
        else if ( root->right != NULL ){
            get_height(root->right,1);
        }
            
        
        return max_height+1;
    }
    
    void rec(Node *node){
        
        if( node->left != NULL )
            rec(node->left);
        
        if(node->right != NULL)
            rec(node->right);
        
        if( node->left != NULL && node->right != NULL ){
            
            int dia = 0;
            max_height = 0;
            get_height(node->left,1);
            dia += max_height;
            max_height = 0;
            get_height(node->right,1);
            dia += max_height;
            max_dia = max(max_dia,dia+1);
        }
            
        
    }
    
    
    void get_height(Node *node, int h){
        
        if(node->left != NULL)
            get_height(node->left,h+1);
        if(node->right!=NULL)
            get_height(node->right,h+1);
        
        max_height = max(max_height,h);
        
    }
    
};