

// Question Link :: "https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1"


// Solution //

class Solution{
  public:
    // Return the Kth smallest element in the given BST 
    int KthSmallestElement(Node *root, int k)
    {
        //add code here.
        int ans = -1, count=0;
        rec(root, ans, count, k);
        return ans;
    }
    
    
    void rec(Node *node, int &ans, int &count, int &k){
        
        if( node->left!=NULL )
            rec(node->left, ans, count, k);
        
        count+=1;
        
        if( k == count )
            ans = node->data;
        
        if( node->right!=NULL )
            rec(node->right,ans, count, k);
        
        
    }
};
