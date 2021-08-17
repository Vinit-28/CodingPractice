

// Question Link :: "https://leetcode.com/problems/count-good-nodes-in-binary-tree/"


// Solution //

class Solution {
public:
    int count;
    int goodNodes(TreeNode* root) {
        
        count = 0;
        traverse(root,INT_MIN);
        return count;
    }
    
    void traverse(TreeNode *node, int currMax){
        
        (node->val >= currMax)? (currMax = node->val, count++) : 0;
        if( node->left != NULL )
            traverse(node->left, currMax);
        
        if( node->right != NULL )
            traverse(node->right, currMax);
    }
};

