

// Question Link :: "https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1"


// Solution //

class Solution {
public:
    void correctBST( struct Node* root )
    {
        // add code here.
        vector<Node*> inOrder;
        Node *firstNode=NULL, *middleNode=NULL, *lastNode=NULL;
        int temp;
        traverse(root, inOrder);
        
        for(int i=1;i<inOrder.size();i++){
            if( inOrder[i]->data < inOrder[i-1]->data ){
                (firstNode==NULL)? (firstNode=inOrder[i-1], middleNode=inOrder[i]) : (lastNode=inOrder[i]);
            }
        }
        
        if( lastNode!=NULL ){
            temp = firstNode->data, firstNode->data = lastNode->data, lastNode->data = temp;
        }
        else if( middleNode!=NULL ){
            temp = firstNode->data, firstNode->data = middleNode->data, middleNode->data = temp;
        }
    }
    
    void traverse(Node *node, vector<Node*> &inOrder){
        
        if( node->left!=NULL )
            traverse(node->left, inOrder);
        inOrder.push_back(node);
        if( node->right!=NULL )
            traverse(node->right, inOrder);
    }
};
