

// Question Link :: "https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1"


// Solution //

class Solution {
  public:
  
    int maxSum;
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        // Your code goes here
        maxSum = INT_MIN;
        getSum(root);
        return maxSum;
    }
    
    int getSum(Node *node){
        
        int leftSum =0, rightSum = 0, ret=node->data;
        
        maxSum = max(maxSum, node->data);
        
        if( node->left!=NULL )
            leftSum = max(leftSum, getSum(node->left));
        
        if( node->right!=NULL )
            rightSum = max(rightSum, getSum(node->right));
        
        if( ret < (ret + leftSum) )
            ret = ret + leftSum;
        
        if( ret < (node->data + rightSum) )
            ret = node->data + rightSum;
        
        maxSum = max(maxSum,  max( (leftSum + node->data + rightSum), max( (leftSum + node->data), (rightSum, node->data) ) ) );
        
        return ret;
    }
};