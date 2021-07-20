

// uestion Link :: "https://practice.geeksforgeeks.org/problems/minimum-depth-of-a-binary-tree/1"


// Solution //

class Solution{
  public:
    /*You are required to complete this method*/
    int minDepth(Node *root) {
        // Your code here
        int ans = INT_MAX;
        rec(root, 1, ans);
        return ans;
    }
    
    void rec(Node *node, int level, int &ans){
        
        if( node->left != NULL )
            rec(node->left, level+1, ans);
        
        if( node->right != NULL )
            rec(node->right, level+1, ans);
        
        if(node->left==NULL && node->right==NULL)
            ans = min(ans, level);
    }
};
