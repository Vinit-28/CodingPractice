

// Question Link :: "https://leetcode.com/problems/binary-search-tree-iterator/"


// Solution //

class BSTIterator {
public:
    
    vector<int> inOrderTraversal;
    int index;
    BSTIterator(TreeNode* root) {
        
        inOrderTraversal.clear();
        index=0;
        traverse(root);
    }
    
    int next() {
        
        return inOrderTraversal[index++];
    }
    
    bool hasNext() {
        
        return index < inOrderTraversal.size();
    }
    
    void traverse(TreeNode *node){
        
        if( node == NULL ) return;
        
        traverse(node->left);
        inOrderTraversal.push_back(node->val);
        traverse(node->right);   
    }
};