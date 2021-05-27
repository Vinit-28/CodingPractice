


//   Question Link :: "https://practice.geeksforgeeks.org/problems/sum-tree/1"



// Solution //


class Solution
{
    public:
    bool signal;
    bool isSumTree(Node* root)
    {
         // Your code here
         
         signal=true;
         rec(root);
         return signal;
    }
    
    
    
    int rec(Node *node){
        
        int sum_of_subtrees = 0;
        bool is_leaf = true;
        
        if(signal==false)
            return 0;
        
        
        if(signal && node->left!=NULL){
            
            is_leaf = false;
            sum_of_subtrees += rec(node->left);
        }
        
        
        if(signal && node->right!=NULL){
            
            is_leaf = false;
            sum_of_subtrees += rec(node->right);
        }
        
        
        if( is_leaf == false && sum_of_subtrees != node->data )
            signal=false;
        
        return node->data+sum_of_subtrees;
        
    }
    
    
};