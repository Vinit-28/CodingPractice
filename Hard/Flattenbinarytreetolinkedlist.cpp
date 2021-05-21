


//   Question Link :: "https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1"




// Solution //


class Solution
{
    public:
    vector<int> pre_order;
    void flatten(Node *root)
    {
        if(root==NULL)
            return;
        pre_order={root->key};
        
        if(root->left!=NULL)
            rec(root->left);
            
        if(root->right!=NULL)
            rec(root->right);
        

        Node *temp=root;
        temp->left=NULL;
        
        for(int i=1;i<pre_order.size();i++)
        {
            temp->right = newNode(pre_order[i]);
            temp = temp->right;
        }
        
    }
    
    
    void rec(Node *node){
        
        
        pre_order.push_back(node->key);
        
        if(node->left!=NULL)
            rec(node->left);
            
        if(node->right!=NULL)
            rec(node->right);
        
    }
    
};