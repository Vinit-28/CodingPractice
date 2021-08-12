

// Question Link :: "https://practice.geeksforgeeks.org/problems/construct-tree-from-preorder-traversal/1#"


// Solution //

void constructTreeHelper(Node *node, int &index, int pre[], char preLN[], int &n){
    
    if( index < n ){
        
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = pre[index];
        node->left = newNode;
        index++;
    }
    
    if( preLN[index-1] != 'L' )
        constructTreeHelper(node->left, index, pre, preLN, n);
    
    
        if( index < n ){
        
            Node *newNode = (Node*)malloc(sizeof(Node));
            newNode->data = pre[index];
            node->right = newNode;
            index++;
        }
    
    if( preLN[index-1] != 'L' )
        constructTreeHelper(node->right, index, pre, preLN, n);
}


struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    if( n == 0 )
        return NULL;
    Node *root = (Node*)malloc(sizeof(Node));
    int index = 1;
    
    root->data = pre[0];
    constructTreeHelper(root, index, pre, preLN, n);
    return root;
}
