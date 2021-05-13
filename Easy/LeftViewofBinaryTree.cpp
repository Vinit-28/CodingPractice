


//   Question Link :: "https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1"



// Solution //



void get_right_side_from_left_view(Node *node, int curr_right_level, int &left_level, vector<int> &ele);


vector<int> leftView(Node *root)
{
   
   vector<int> ele={};
   int left_level=0;
   Node *left=root;
   
   if (root==NULL)
        return ele;
   
   while(true){
        ele.push_back(left->data);
        left_level++;
        
        if(left->left!=NULL)
            left= left->left;
        else if ( left->right!=NULL)
            left=left->right;
        else
            break;
   }
   
   if(root->right!=NULL){
     get_right_side_from_left_view(root->right,2,left_level,ele);
   }
   
   return ele;
   
}



void get_right_side_from_left_view(Node *node, int curr_right_level, int &left_level, vector<int> &ele){
    
    if(curr_right_level > left_level){
        
        ele.push_back(node->data);
        left_level+=1;
    }
    
    if(node->left!=NULL){
        
        get_right_side_from_left_view(node->left, curr_right_level+1,left_level,ele);
    }
    
    if(node->right!=NULL){
        
        get_right_side_from_left_view(node->right, curr_right_level+1,left_level,ele);
    }
}