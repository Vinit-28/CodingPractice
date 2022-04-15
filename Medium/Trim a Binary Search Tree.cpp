

// Question Link :: "https://leetcode.com/problems/trim-a-binary-search-tree/"


// Solution //

class Solution {
public:
    TreeNode* trimBST(TreeNode* node, int &low, int &high) {
        
        if(node == NULL ) return NULL;
        if( node->val < low ) return trimBST(node->right, low, high);
        if( node->val > high ) return trimBST(node->left, low, high);
        
        node->left = trimBST(node->left, low, high);
        node->right = trimBST(node->right, low, high);
        
        return node;
    }
};