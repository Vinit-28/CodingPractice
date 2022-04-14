

// Question Link :: "https://leetcode.com/problems/search-in-a-binary-search-tree/"


// Solution //

class Solution {
public:
    TreeNode* searchBST(TreeNode* node, int &val) {
        
        if( node==NULL ) return NULL;
        
        if( node->val == val ) return node;
        
        TreeNode *search;
        
        if( val < node->val ){
            search = searchBST(node->left, val);
            if( search != NULL ) return search;
        }
        
        else{
            search = searchBST(node->right, val);
            if( search != NULL ) return search;
        }
        
        return NULL;
    }
};