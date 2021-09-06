

// Question Link :: "https://practice.geeksforgeeks.org/problems/print-bst-elements-in-given-range/1"


// Solution //

class Solution {
  public:
    vector<int> printNearNodes(Node *root, int low, int high) {
        //code here 
        vector<int> ans;
        traverse(root, low, high, ans);
        return ans;
    }
    
    
    void traverse(Node *node, int &low, int &high, vector<int> &ans){
        
        if( node->left!=NULL )
            traverse(node->left, low, high, ans);
        
        if( node->data >= low && node->data <= high )
            ans.push_back(node->data);
        
        if( node->right!=NULL )
            traverse(node->right, low, high, ans);
    }
};
