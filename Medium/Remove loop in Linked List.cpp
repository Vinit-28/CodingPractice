

// Question Link :: "https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1"


// Solution //

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if( head == NULL || head->next == NULL || head->next->next == NULL )
            return;
            
        Node *slow=head->next, *fast=head->next->next, *temp, *collision=NULL;
        
        while(fast!=NULL && fast!=slow){
            
            if( fast->next == NULL || fast->next->next == NULL )
                return;
            
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if( fast==NULL )
            return;
        temp = head, collision = fast;
        
        if( temp == collision ){
            while( collision->next != temp)
                collision=collision->next;
        }
        
        else{
            
            while( collision->next != temp->next )
                collision=collision->next, temp = temp->next;
        }
        
        collision->next = NULL;
    }
};
