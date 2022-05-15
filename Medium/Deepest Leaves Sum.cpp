

// Question Link :: "https://leetcode.com/problems/deepest-leaves-sum/"


// Solution //

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        
        int deepestLevel = 1, deepestLevelSum = 0;
        
        // Finding deepest level //         
        findDeepestLevel(root->left, 2, deepestLevel);
        findDeepestLevel(root->right, 2, deepestLevel);
        
        // Getting the deepest level sum //         
        findLevelSum(root, 1, deepestLevel, deepestLevelSum);
        
        return deepestLevelSum;
    }
    
    void findDeepestLevel(TreeNode *node, int currLevel, int &maxLevel){
        
        if( node == NULL ) return;
        maxLevel = max(maxLevel, currLevel);
        findDeepestLevel(node->left, currLevel+1, maxLevel);
        findDeepestLevel(node->right, currLevel+1, maxLevel);
    }
    
    void findLevelSum(TreeNode *node, int currLevel, int &targetLevel, int &sum){
        
        if( node == NULL ) return;
        sum = (targetLevel == currLevel)? sum + node->val : sum;
        findLevelSum(node->left, currLevel+1, targetLevel, sum);
        findLevelSum(node->right, currLevel+1, targetLevel, sum);
    }
};