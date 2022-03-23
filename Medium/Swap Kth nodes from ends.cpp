

// Question Link :: "https://practice.geeksforgeeks.org/problems/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list/1#"


// Solution //

Node *back1, *mid1, *next1;
Node *back2, *mid2, *next2;
Node *temp;


void traverse(Node *node, int &k, int index, int &totalLen){
    
    if( node == NULL ) return;
    
    totalLen += 1;
    traverse(node->next, k, index+1, totalLen);
    
    back1 = (index == k-1)? node : back1;
    mid1 = (index == k)? node : mid1;
    next1 = (index == k+1)? node : next1;
    
    
    back2 = (index == (totalLen-k) )? node : back2;
    mid2 = (index == (totalLen-k+1) )? node : mid2;
    next2 = (index == (totalLen-k+2) )? node : next2;
}

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int k)
{
    // Your Code here
    int totalLen = 0;
    back1 = back2 = next1 = next2 = mid1 = mid2 = NULL;
    traverse(head, k, 1, totalLen);
    
    if( mid1 != NULL && mid2 != NULL ){
        
        // Mid2 -> Mid1 //
        if( mid2 == back1 ){
            
            if( back2 != NULL ){
                back2->next = mid1;
            }
            mid1->next = mid2, mid2->next = next1;
        }
        // Mid1 -> Mid2 //
        else if( mid1 == back2 ){
            
            if( back1 != NULL ){
                back1->next = mid2;
            }
            mid2->next = mid1, mid1->next = next2;
        }
        else{
            
            if( back1 != NULL ){
                back1->next = mid2;
            }
            if( back2 != NULL ){
                back2->next = mid1;
            }
            mid1->next = next2;
            mid2->next = next1;
        }
    }
    
    return (k==1)? mid2 : (k==totalLen)? mid1 : head;
}
