

// Question Link :: "https://practice.geeksforgeeks.org/problems/rearrange-a-linked-list/1#"


// Solution //

class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
        // Your Code here
        if( head == NULL || head->next == NULL || head->next->next == NULL )
            return ;
        
        Node *lastOdd = head, *lastEven=head->next, *currNode = head, *temp1, *temp2,  *nextNode;
        int pos = 1;
        
        while( currNode!=NULL ){
            
            nextNode = currNode->next;
            
            if( pos!=1 && pos%2!=0 ){
                
                temp1 = lastOdd->next, lastOdd->next = currNode, temp2 = currNode->next; 
                currNode->next = temp1, lastEven->next = temp2;
                lastEven = temp2, lastOdd = currNode;
            }
            
            currNode = nextNode;
            pos+=1;
        }
        
    }
};
