

// Question Link :: "https://leetcode.com/problems/convert-bst-to-greater-tree/"


// Solution //

class Solution {
public:
    
    
    TreeNode* convertBST(TreeNode* root) {
        
        traverse(root, 0);
        return root;
    }
    
    int traverse(TreeNode *node, int sum){
        
        if( node == NULL ) return 0;
        
        int val = node->val;
        int rightSum = traverse(node->right, sum);
        rightSum = (rightSum==0)? sum : rightSum;
        
        int left = traverse(node->left, rightSum + val);
        
        node->val += rightSum;
        
        return (left==0)? node->val : left;
    }
};