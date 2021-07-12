

// Question Link :: "https://practice.geeksforgeeks.org/problems/check-for-bst/1"


// Solution //

class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        vector<int> elements;
        getInorder(root, elements);
        
        for(int i=0;i<elements.size()-1;i++)
            if( elements[i] >= elements[i+1] )
                return false;
        return true;
    }
    
    void getInorder(Node *node, vector<int> &elements){
        
        if( node->left!=NULL )
            getInorder(node->left, elements);
        
        elements.push_back(node->data);
        
        if( node->right!=NULL )
            getInorder(node->right, elements);
    }
};
