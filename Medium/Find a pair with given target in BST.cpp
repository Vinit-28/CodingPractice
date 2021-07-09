

// Question Link :: "https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1"


// Solution //

class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    map<int, bool> nodesValue;
    int isPairPresent(struct Node *root, int target)
    {
        nodesValue.clear();
        bool isFound = false;
        traverse(root,target,isFound);
        
        if( isFound )
            return 1;
        return 0;
    }
    
    void traverse(Node *node, int &target, bool &isFound){
        
        if( nodesValue[(target-node->data)] ){
            isFound = true;
            return;
        }
        
        nodesValue[node->data] = true;
        if(isFound == false && node->left != NULL)
            traverse(node->left,target,isFound);
        
        if(isFound == false && node->right != NULL)
            traverse(node->right,target,isFound);
    }
};