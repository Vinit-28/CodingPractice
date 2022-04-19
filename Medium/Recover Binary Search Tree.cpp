

// Question Link :: "https://leetcode.com/problems/recover-binary-search-tree/"


// Solution //

class Solution {
public:
    
    TreeNode *wrong1, *wrong2, *lastMinNode, *temp;
    void recoverTree(TreeNode* root) {
        
        wrong1 = wrong2 = lastMinNode = temp = NULL;
        findWrongNodes(root);
        
        if( wrong1 != NULL && wrong2 != NULL ) swapNodeValues(wrong1, wrong2);
        else if( wrong1 != NULL && temp != NULL ) swapNodeValues(wrong1, temp);
    }
    
    void findWrongNodes(TreeNode *node){
        
        if( !node ) return;
        
        findWrongNodes(node->left);
        
        if( lastMinNode != NULL && node->val < lastMinNode->val ){
            if( wrong1 == NULL ) wrong1 = lastMinNode, lastMinNode = node, temp = node;
            else wrong2 = node;
        }
        else lastMinNode = node;
        
        findWrongNodes(node->right);
    }
    
    void swapNodeValues(TreeNode *node1, TreeNode *node2){
       
        node1->val ^= node2->val;
        node2->val ^= node1->val;
        node1->val ^= node2->val;
    }
};