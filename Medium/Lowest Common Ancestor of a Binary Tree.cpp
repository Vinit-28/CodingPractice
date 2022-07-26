

// Question Link :: "https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/"


// Solution //

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return DFS(root, p, q);
    }
    
    TreeNode* DFS(TreeNode *node, TreeNode *p, TreeNode *q){
        
        if( node != NULL ){
            
            if( node == p || node == q ) return node;
            
            TreeNode *left = DFS(node->left, p, q);
            TreeNode *right = DFS(node->right, p, q);
            
            // Returning the parent itself //             
            if( left != NULL && right != NULL ) return node;
            
            
            return left != NULL? left : right;
        }   
        return NULL;
    }
};