

// Question Link :: "https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1"


// Solution //

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        vector<int> t1, t2;
        if( r1!=NULL )
            rec(t1, r1);
        if( r2!=NULL )
            rec(t2, r2);
        
        return (t1==t2);
    }
    
    void rec(vector<int> &tree, Node *node){
        
        tree.push_back(node->data);
        
        if( node->left != NULL )
            rec(tree, node->left);
        
        if( node->right != NULL )
            rec(tree, node->right);
    }
   
};
