

// Question Link :: "https://practice.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1"


// Solution //

void findSum(long long int &sum, Node *node, string path){
    
    if( node->left != NULL )
        findSum(sum, node->left, path+char(node->left->data+48));
    
    if( node->right != NULL )
        findSum(sum, node->right, path+char(node->right->data+48));
    
    if( node->left == NULL && node->right == NULL )
        sum += stoi(path);
}


long long treePathsSum(Node *root)
{
    //Your code here
    long long int sum = 0;
    findSum(sum, root, to_string(root->data));
    return sum;
}
