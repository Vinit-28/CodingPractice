

// Question Link :: "https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1"


// Solution //

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
   // Your code here
    int len = 0;
    Node *temp=head;
    while(temp!=NULL)
        temp = temp->next, len++;
    
    temp = head;
    if( n>len )
        return -1;
    
    while(len > n)
        temp = temp->next, len--;
    return temp->data;
}
