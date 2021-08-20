

// Question Link :: "https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3903/"


// Solution //

class Solution {
public:
    long long int ans, totalSum, mod = 1000000007;
    int maxProduct(TreeNode* root) {
        
        ans = 0;
        totalSum = getSum(root);
        findAns(root);
        return ans%mod;
    }
 
    
    long long int findAns(TreeNode *node){
        
        long long int sum=node->val;
        
        if( node->left!=NULL )
                sum += findAns(node->left);
        
        if( node->right!=NULL )
                sum += findAns(node->right);
        
        
        ans = max( ans, ((totalSum-sum)* sum ) );
        return sum;
    }

    
    long long int getSum(TreeNode *node){
        
        long long int sum=node->val;
        
        if( node->left!=NULL )
                sum += getSum(node->left);
        
        if( node->right!=NULL )
                sum += getSum(node->right);
        
        return sum;
    }
};