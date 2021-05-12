

//   Question Link :: "https://practice.geeksforgeeks.org/problems/burning-tree/1"



// Solution //

class Solution {
    public:
    
    int l_height=0,r_height=0,target_data, max_sec=0;
    bool is_target_reached=false;
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        int total_seconds=0;
        target_data = target;
        
        if( root->left != NULL )
            process_data(root->left,1,'L',0);
        
        if( is_target_reached ){
            
            total_seconds = root->left->data+1;
            count_depth(root->right, 1, 'R');
            total_seconds = max((total_seconds+r_height), max_sec);
        }
        else{
            
            if( root->right != NULL )
                process_data(root->right,1,'R',0);
            
            if ( is_target_reached ){
                
                total_seconds = root->right->data+1;
                total_seconds = max((total_seconds+l_height), max_sec);
            }
        }
        
        return total_seconds;
    }
    
    
    void count_depth(Node *node, int curr_height, char side){
        
        if(node->left != NULL){
                
            count_depth(node->left, curr_height+1, side);
        }
        
        if(node->right != NULL){
            
            count_depth(node->right, curr_height+1, side);
        }
        
        if( side == 'L' ){
                
            l_height = max(l_height, curr_height);
        }
        
        else if( side == 'R' ){
            
            r_height = max(r_height, curr_height);
        }
    }
    
    
    int process_data(Node *node, int curr_height, char side, int value_to_store){
        
        if(is_target_reached==false && node->data == target_data){
            
            is_target_reached=true;
            node->data = 0;
            return node->data+1;
        }
        
        
        if( is_target_reached ){
            
            node->data = value_to_store;
            
            if(node->left != NULL){
                
                process_data(node->left, curr_height+1, side, node->data+1);
            }
            
            if(node->right != NULL){
                
                process_data(node->right, curr_height+1, side, node->data+1);
            }
            
            max_sec = max(max_sec,node->data);
        }
        
        
        else{
            
            if(node->left != NULL){
                
                int val = process_data(node->left, curr_height+1, side,value_to_store);
                
                if( is_target_reached ){
                    
                    node->data = val;
                    
                    if(node->right!=NULL){
                        
                        process_data(node->right, curr_height+1, side, node->data+1);
                    }
                    
                    max_sec = max(max_sec,node->data);
                    return node->data+1;
                }
                
            }
            
            if(node->right != NULL){
                
                int val = process_data(node->right, curr_height+1, side,value_to_store);
                
                if( is_target_reached ){
                    
                    node->data = val;
                    
                    if(node->left!=NULL){
                        
                        process_data(node->left, curr_height+1, side, node->data+1);
                    }
                    
                    max_sec = max(max_sec,node->data);
                    return node->data+1;
                }
                
            }
            
            if( side == 'L' && l_height < curr_height ){
                
                l_height = curr_height;
            }
            
            else if( side == 'R' && r_height < curr_height ){
                
                r_height = curr_height;
            }
        
        }
        return 0;
    }
    
};
