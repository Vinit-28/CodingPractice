

// Question Link :: "https://practice.geeksforgeeks.org/problems/given-a-linked-list-reverse-alternate-nodes-and-append-at-the-end/1"


// Solution //

class Solution
{
    public:
    void rearrange(struct Node *head)
    {
        //add code here
        if( head == NULL || head->next == NULL || head->next->next == NULL )
            return;
        
        Node *oddHead = head, *evenHead = head->next;
        Node *lastOdd = oddHead, *lastEven = evenHead, *currNode=evenHead, *temp, *backup;
        int count = 2;
        
        while(currNode != NULL){
            
            if( count%2 == 0 ){
                lastOdd->next = currNode->next, currNode = lastOdd->next;
                lastOdd = (lastOdd->next==NULL)? lastOdd : lastOdd->next;
            }
            else{
                lastEven->next = currNode->next, currNode = lastEven->next;
                lastEven = lastEven->next;
            }
            count++;
        }
        
        currNode = evenHead;
        while(currNode != NULL){
            
            backup = currNode->next;
            temp = lastOdd->next;
            lastOdd->next = currNode;
            currNode->next = temp;
            
            currNode = backup;
        }

    }
};
