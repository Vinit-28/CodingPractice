

// Question Link :: "https://leetcode.com/problems/maximum-depth-of-binary-tree/"


// Solution //

class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if( root == NULL ) return 0;
        int left = maxDepth(root->left), right = maxDepth(root->right);
        return max(left, right)+1;
    }
};