

// Question Link :: "https://practice.geeksforgeeks.org/problems/postorder-traversal-iterative/1"


// Solution //

vector<int> postOrder(Node* root) {
    // code here
    
    vector<int> preorder_traversal;
    vector<Node*> nodes = {root};
    vector<bool> is_left_visited = {false},is_right_visited = {false};
    
    int len=1;
    
    while(len>0){
        
        if( is_left_visited[len-1] == false && nodes[len-1]->left!=NULL ){
            
            nodes.push_back(nodes[len-1]->left);
            is_left_visited[len-1]=true;
            
            is_left_visited.push_back(false);
            is_right_visited.push_back(false);
            len+=1;
            
            continue;
        }
        else{
            
            is_left_visited[len-1]=true;
            
        }
        
        if( is_right_visited[len-1] == false && nodes[len-1]->right!=NULL ){
            
            nodes.push_back(nodes[len-1]->right);
            is_right_visited[len-1]=true;
            
            is_left_visited.push_back(false);
            is_right_visited.push_back(false);
            len+=1;
        }
        else{
            preorder_traversal.push_back(nodes[len-1]->data);
            nodes.pop_back();
            is_left_visited.pop_back();
            is_right_visited.pop_back();
            len-=1;
        }
        
    }
    
    return preorder_traversal;

}