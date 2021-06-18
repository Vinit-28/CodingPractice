

// Question Link :: "https://practice.geeksforgeeks.org/problems/maximum-path-sum/1#"


// Solution //


class Solution {
public:
    
    int max_sum;
    int maxPathSum(Node* root)
    {
        // code here
        max_sum = INT_MIN;
        int special_case_sum = get_max_sum(root);
        
        if( max_sum == INT_MIN )
            return special_case_sum;
        return max_sum;
    }
    
    
    int get_max_sum(Node *node){
        
        int left_sum=0,right_sum=0;
        
        bool is_left_present = false, is_right_present = false;
        
        if( node->left!=NULL ){
            
            left_sum = get_max_sum(node->left);
            is_left_present = true;
        }
        
        if( node->right != NULL ){
            
            right_sum = get_max_sum(node->right);
            is_right_present = true;
        }
        
        if( is_left_present == false && is_right_present == false ){
            
            return node->data;
        }
        
        
        if( is_left_present && is_right_present ){
            
            max_sum = max(max_sum, ( node->data + left_sum + right_sum ) );
        
        
            if( left_sum >= right_sum )
                return(node->data + left_sum);
            else
                return(node->data + right_sum);
            
        }
        
        
        return( node->data + left_sum + right_sum );      
    }
};

