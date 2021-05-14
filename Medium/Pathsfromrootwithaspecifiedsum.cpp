


//   Question Link :: "https://practice.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1"



// Solution //


class Solution
{
    public:
    vector<vector<int>> paths;
    int target_sum;
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        //code here
        paths.clear();
        target_sum = sum;
        find_sum_with_path(root->key,root,{root->key});
        return paths;
    }
    
    void find_sum_with_path(int sum, Node *node, vector<int> curr_path){
        
        if(sum > target_sum)
            return;
        if( sum == target_sum ){
            
            
            paths.push_back(curr_path);
            return;
        }
        
        
        if( node->left != NULL ){
            
            curr_path.push_back(node->left->key);
            find_sum_with_path(sum+(node->left->key), node->left, curr_path);
            curr_path.pop_back();
        }
        
        if( node->right != NULL ){
            
            curr_path.push_back(node->right->key);
            find_sum_with_path(sum+(node->right->key), node->right, curr_path);
            curr_path.pop_back();
        }
    }
};
