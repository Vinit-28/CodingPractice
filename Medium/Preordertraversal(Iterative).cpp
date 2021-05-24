


// Question Link :: "https://practice.geeksforgeeks.org/problems/preorder-traversal-iterative/1"



// Solution //



vector<int> preOrder(Node* root)
{
    //code here
    vector<int> ans;
    vector<bool> is_visited;
    vector<Node*> nodes;
    
    nodes.push_back(root);
    ans.push_back(root->data);
    is_visited.push_back(true);
    
    int len = 1;
    
    while(len){
        
        if(is_visited[len-1] ==  false){
            
            ans.push_back(nodes[len-1]->data);
            is_visited[len-1]=true;    
        }
        
        
        if(nodes[len-1]->left!=NULL){
            
            nodes.push_back(nodes[len-1]->left);
            nodes[len-1]->left=NULL;
            is_visited.push_back(false);
            len+=1;
            
        }
        else if(nodes[len-1]->right!=NULL){
            
            nodes.push_back(nodes[len-1]->right);
            nodes[len-1]->right=NULL;
            is_visited.push_back(false);
            len+=1;
            
        }
        else{
            nodes.pop_back();
            is_visited.pop_back();
            len-=1;
        }
        
    }
    
    
    return ans;
}
