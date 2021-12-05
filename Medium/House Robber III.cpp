

// Question Link :: "https://leetcode.com/problems/house-robber-iii/"


// Solution //

class Solution {
public:
    int rob(TreeNode* root) {
        
        map<TreeNode*, int> inc, exc;
        return DFS(root, 'E', inc, exc);
    }
    
    
    int DFS(TreeNode *node, char sign, map<TreeNode*, int> &inc, map<TreeNode*, int> &exc){
        
        if( node==NULL ) return 0;
       
        if( exc.find(node) == exc.end() ){
            
            int ifIncLeft = DFS(node->left, 'I', inc, exc) + node->val, ifExcLeft = DFS(node->left, 'E', inc, exc);
            int ifIncRight = DFS(node->right, 'I', inc, exc) + node->val, ifExcRight = DFS(node->right, 'E', inc, exc);

            inc[node] = (ifIncLeft + ifIncRight)-node->val, exc[node] = (ifExcLeft + ifExcRight);
        }
        
        if( sign == 'I' ) return exc[node];
        return max(inc[node], exc[node]);
    }
};