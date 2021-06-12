

// Question Link :: "https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#"



// Solution //

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int len1=0,len2=0,dif;
    Node *temp1=head1,*temp2=head2,*big,*small;
    
    
    while(true){
        
        if( temp1!=NULL )
            len1+=1,temp1=temp1->next;
            
        
        if( temp2!=NULL )
            len2+=1,temp2=temp2->next;
        
        if( temp1==NULL && temp2==NULL )
            break;
    }
    
    if( len1>len2 )
        big = head1,small=head2,dif=len1-len2;
    else
        big = head2,small=head1,dif=len2-len1;
        
    while(big!=NULL){
        
        if( dif == 0  ){
            
            if( small == big )
                return small->data;
            
            small = small->next;
            
        }
        else
            dif-=1;
            
        big = big->next;
    }
    return -1;
}
