

// Question Link :: "https://leetcode.com/problems/merge-two-binary-trees/"


// Solution //

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        return DFS(root1, root2);
    }
    
    
    TreeNode* DFS(TreeNode *node1, TreeNode *node2){
        
        TreeNode *newNode = new TreeNode(0);
        if( node1 != NULL && node2 != NULL ){
            newNode->val = (node1->val + node2->val);
            newNode->left = DFS(node1->left, node2->left);
            newNode->right = DFS(node1->right, node2->right);
        }
        else if( node1 != NULL ){
            newNode->val = (node1->val);
            newNode->left = DFS(node1->left, NULL);
            newNode->right = DFS(node1->right, NULL);
        }
        else if( node2 != NULL ){
            newNode->val = (node2->val);
            newNode->left = DFS(NULL, node2->left);
            newNode->right = DFS(NULL, node2->right);
        }
        else
            newNode = NULL;
        
        return newNode;
    } 
    
};