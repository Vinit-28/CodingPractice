

// Question Link :: "https://leetcode.com/problems/maximum-width-of-binary-tree/"


// Solution //

class Solution {
public:

    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> q;
        long maxWidth = 1, size, left, right; 
        q.push( {root, 0} );
        
        while( q.empty() == false ){
            
            size = q.size(), left = q.front().second, right = q.back().second;
            maxWidth = max(maxWidth, (right-left)+1);
            
            while( size ){
                
                auto p = q.front();
                long idx = p.second;
                q.pop();
            
                if( p.first->left != NULL ) q.push( {p.first->left, idx*2+1 } );
                
                if( p.first->right != NULL ) q.push( {p.first->right, idx*2+2 } );
                
                size -= 1;
            }
        }
        
        return maxWidth;
    }
};