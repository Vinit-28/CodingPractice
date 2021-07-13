

// Question Link :: "https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1"


// Solution //

class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        if( head==NULL || head->next==NULL || head->next->next==NULL )
            return false;
            
        Node *slow=head->next, *fast=slow->next;
        while(fast!=NULL){
            
            if( fast == slow )
                return true;
            
            if( fast->next == NULL || fast->next->next == NULL)
                return false;
            
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};
