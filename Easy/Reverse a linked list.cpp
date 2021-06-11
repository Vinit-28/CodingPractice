

// Question Link :: "https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1"


// Solution //

#include<vector>

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        vector<struct Node*> nodes;
        Node *temp=head;
        int len = 0,temp1,j,i;
        
        while (temp!=NULL){
            nodes.push_back(temp);
            temp=temp->next;
            len+=1;
        }
        
        for(i=0,j=len-1;i<(len/2);i+=1,j-=1){
            
            temp1 = nodes[i]->data;
            nodes[i]->data = nodes[j]->data;
            nodes[j]->data = temp1;
            
        }
        
        return head;
    }
    
};
 