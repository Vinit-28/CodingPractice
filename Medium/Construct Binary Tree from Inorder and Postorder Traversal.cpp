

// Question Link :: "https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/"


// Solution //

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        map<int, int> hash;
        TreeNode *root = NULL;
        
        if( n>0 ){
            for(int i=0;i<n;i++) hash[inorder[i]] = i;
            for(int i=n-1;i>=0;i--)
                if( i==n-1 ) root = new TreeNode(postorder[i]);
                else Insert(root, postorder[i], hash);
        }
        return root;
    }
    
    
    void Insert(TreeNode *node, int &val, map<int, int> &hash){
        
        TreeNode *temp;
        char move;
        while(node!=NULL)
            if( hash[node->val] < hash[val] )
                temp = node, node = node->right, move='r';
            else
                temp = node, node = node->left, move='l';
        
        if( move == 'l' ) temp->left = new TreeNode(val);
        else temp->right = new TreeNode(val);
    }
    
};