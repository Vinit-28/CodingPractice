

// Question Link :: "https://leetcode.com/problems/reorder-list/"


// Solution //

class Solution {
public:
    void reorderList(ListNode* head) {
        
        vector<ListNode*> myStack;
        int len = 0, mid, index=0;
        ListNode *temp=head, *next, *curr=head, *temp2;
        while(temp!=NULL) myStack.push_back(temp), temp = temp->next, len++;
        mid = len/2;
        temp = curr = head;
        
        while(index<mid){
            next = curr->next;
            curr->next = myStack.back();
            myStack.pop_back();
            curr->next->next = next;
            
            temp = curr->next;
            curr = next;
            index++;
        }
        
        if( temp == curr ) temp->next = NULL;
        else curr->next = NULL;
    }
};