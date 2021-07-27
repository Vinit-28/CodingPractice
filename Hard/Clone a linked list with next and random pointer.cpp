

// Question Link :: "https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1"


// Solution //

class Solution
{
    public:
   
    Node *copyList(Node *head)
    {
        //Write your code here
        Node *newHead=NULL, *temp1, *temp2=NULL, *temp3=NULL;
       
        // ----- Inerting Nodes In Betweeen ----- //
        temp1=head;
        while(temp1!=NULL){
            
            temp2 = temp1->next;
            auto newNode = (Node*)malloc(sizeof(Node));
            newNode->data = temp1->data;
            newNode->next = temp2, temp1->next = newNode;
            temp1=temp2;
        }
      
        // ----- Connecting Random Connections ----- //
        temp1 = head;
        for(int i=1; temp1!=NULL; i++,temp1=temp1->next)
            if( i%2 == 0 )
                (temp2->arb==NULL)? (temp1->arb=NULL) : (temp1->arb = temp2->arb->next);
            else
                temp2=temp1;
    
        // ----- Seperating the Linked Lists ----- //
        newHead = head->next, temp1 = head;
        temp3=temp2=NULL;
        
        for(int i=1; temp1!=NULL; i++,temp1=temp1->next)
            if( i%2 == 0 )
                (temp3==NULL)? (temp3=newHead) : (temp3->next=temp1, temp3=temp1); 
            else
                (temp2==NULL)? (temp2=head) : (temp2->next=temp1, temp2=temp1);
        
        temp2->next = NULL;
        return newHead;
    }
};