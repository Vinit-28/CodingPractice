

// Question Link :: "https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3908/"


// Solution //

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> arr;
        inOrder(root, arr);
        int left=0, right=arr.size()-1;
        
        while(left < right){
            
            if( (arr[left] + arr[right]) == k )
                return true;
            
            ((arr[left] + arr[right]) > k)? (right--) : (left++);
        }
        return false;
    }
    
    void inOrder(TreeNode *node, vector<int> &arr){
        
        if( node->left != NULL )
            inOrder(node->left, arr);
        
        arr.push_back(node->val);
        
        if( node->right != NULL )
            inOrder(node->right, arr);
        
    }
};