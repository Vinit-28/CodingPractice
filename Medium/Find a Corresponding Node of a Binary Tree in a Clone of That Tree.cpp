

// Question Link :: "https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/"


// Solution //

class Solution {
public:
    
    TreeNode *ans;
    bool isFound;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        ans = NULL, isFound = false;
        traverse(cloned, target);
        return ans;
    }
    
    void traverse(TreeNode *node, TreeNode *target){
        
        if( isFound || node==NULL ) return;
        
        if( node->val == target->val ){
            ans = node, isFound = true;
            return;
        }
        
        traverse(node->left, target);
        traverse(node->right, target);
    }
};