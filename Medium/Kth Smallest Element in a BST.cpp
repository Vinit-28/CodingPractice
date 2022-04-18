

// Question Link :: "https://leetcode.com/problems/kth-smallest-element-in-a-bst/"


// Solution //

class Solution {
public:
    int ans;
    int kthSmallest(TreeNode* root, int k) {
        
        ans = -1;
        traverse(root, k);
        return ans;
    }
    
    void traverse(TreeNode *node, int &k){
        
        if( node->left != NULL ) traverse(node->left, k);
        
        k -= 1;
        if( k==0 ) ans = node->val;
        
        if( node->right != NULL ) traverse(node->right, k);
        
    }
};