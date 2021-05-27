


//   Question Link :: "https://practice.geeksforgeeks.org/problems/sorted-list-to-bst/1"



// Solution //


int get_len(LNode *head){
    
    int l=0;
    while (head!=NULL)
        l+=1,head=head->next;
    return l;
}

void binary(int index, int data, int len, TNode *root){
        
    int l=0, u=len-1, m = (u+l+1)/2;

    TNode *temp = root;
    
    while (true){
        
        if (m == index)
            break;
        
        else if (m > index){
            
            if (temp->left==NULL)
                temp->left = (TNode*)malloc(sizeof(TNode));
            temp=temp->left;
            u=m-1;
        }
        
        else{
            
            if (temp->right==NULL)
                temp->right = (TNode*)malloc(sizeof(TNode));
            temp=temp->right;
            l=m+1;
        }
        
        m=(u+l+1)/2;
    }
    
    temp->data = data;
    
}

TNode* sortedListToBST(LNode *head)
{
    //code here
    
    TNode *root = (TNode*)malloc(sizeof(TNode));
    int i=0, len = get_len(head);
    while (head!=NULL){
        
        binary(i,head->data,len,root);
        i+=1;
        head = head->next;
    }
    return root;
}

