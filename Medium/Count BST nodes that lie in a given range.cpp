

// Qusetion Link :: "https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1"


// Solution //

void rec(Node *node, int l, int h, int &count){
    
    if( node->data >= l && node->data <= h)
        count+=1;
        
    if(node->left!=NULL && node->data > l)
        rec(node->left, l, h, count );
    
    if( node->right!=NULL && node->data < h )
        rec(node->right, l, h, count);
    
}


//Function to count number of nodes in BST that lie in the given range.
int getCount(Node *root, int l, int h)
{
  // your code goes here   
  int count =0;
  
  rec(root, l,h, count);
  return count;
}