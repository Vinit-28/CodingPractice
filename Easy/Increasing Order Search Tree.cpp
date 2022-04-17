

// Question Link :: "https://leetcode.com/problems/increasing-order-search-tree/"


// Solution //

class Solution {
public:
    
    TreeNode *newRoot, *lastNode;
    TreeNode* increasingBST(TreeNode* root) {
        
        newRoot = lastNode = NULL;
        traverse(root);
        return newRoot;
    }
    
    void traverse(TreeNode *node){
        
        if( node->left != NULL ) traverse(node->left);
        
        (lastNode != NULL)? (lastNode->right = node, lastNode = node) : (lastNode = newRoot = node);
        
        if( node->right != NULL ) traverse(node->right);
        
        node->left = NULL;
    }
};