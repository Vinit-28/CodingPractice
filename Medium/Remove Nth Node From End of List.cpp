

// Question Link :: "https://leetcode.com/problems/remove-nth-node-from-end-of-list/"


// Solution //

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *ahead=head, *curr, *prev=NULL;
        int pos=0;
        while(pos<n) ahead=ahead->next,pos++;
        curr=head;
        while(ahead!=NULL)
            prev = curr, ahead=ahead->next, curr=curr->next;
        if( prev == NULL ) return head->next;
        prev->next = curr->next;
        return head;
    }
};