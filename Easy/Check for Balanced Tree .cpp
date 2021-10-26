

// Question Link :: "https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1"


// Solution //

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int maxDiff;
    bool isBalanced(Node *root)
    {
        //  Your Code here
        maxDiff=INT_MIN;
        DFS(root);
        return (maxDiff <= 1);
    }
    
    int DFS(Node *node){
        
        int leftHeight=0, rightHeight=0;
        
        if( node->left!=NULL ){
            leftHeight = DFS(node->left);
        }
        if( node->right!=NULL ){
            rightHeight = DFS(node->right);
        }
        
        maxDiff = max(maxDiff, abs(leftHeight - rightHeight));
        return max(leftHeight, rightHeight)+1;
    }
};
