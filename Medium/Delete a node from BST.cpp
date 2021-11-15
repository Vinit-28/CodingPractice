

// Question Link :: "https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1"


// Solution //

int getMax(Node *node){
    
    if( node->right != NULL ) return getMax(node->right);
    return node->data;
}



// Function to delete a node from BST.
Node *deleteNode(Node *node, int X) {
    
    if( node == NULL ) return NULL;
    
    if( X > node->data ){
        node->right = deleteNode(node->right, X);
    }
    else if( X < node->data ){
        node->left = deleteNode(node->left, X);
    }
    else{
        
        if( node->left != NULL && node->right != NULL ){
            node->data = getMax(node->left);
            node->left = deleteNode(node->left, node->data);
        }
        else if( node->left != NULL ){
            return node->left;
        }
        else if( node->right != NULL ){
            return node->right;
        }
        else{
            return NULL;
        }
    }
    return node;
}
