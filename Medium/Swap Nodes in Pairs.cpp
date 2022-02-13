

// Question Link :: "https://leetcode.com/problems/swap-nodes-in-pairs/"


// Solution //

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if( head==NULL || head->next == NULL ) return head;
        
        ListNode *curr1=head, *curr2=head->next, *next1, *next2, *lastModified=NULL;
        head = NULL;
        
        while(curr1 != NULL && curr2 != NULL){
            
            next1 = curr2->next, next2 = (next1==NULL)? NULL : next1->next;
            
            curr1->next = curr2->next;
            curr2->next = curr1;
            head = (head==NULL)? curr2 : head;
            (lastModified==NULL)? (lastModified = curr2) : (lastModified->next=curr2);
            
            lastModified = curr1, curr1 = next1, curr2=next2;
        }
        (curr2==NULL)? (curr1==NULL)? NULL : (curr1->next=NULL) : (curr2->next=NULL);
        return head;
    }
};