

// Question Link :: "https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/"


// Solution //

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if( head == NULL || head->next==NULL ) return head;
        
        ListNode *temp1=head, *temp2=head->next, *newHead, *prev, *prevToPrev;
        newHead = new ListNode(101);
        newHead->next = head, prevToPrev = prev = newHead;
        
        while(temp2!=NULL){
            
            if( temp2->val == temp1->val ){
                
                while(temp2!=NULL && temp2->val == temp1->val){
                    temp1->next = temp2->next, temp2 = temp2->next;
                }
                prev->next = temp1->next, temp1 = prev, temp2 = prev->next, prev=prevToPrev;
            }
            else{
                prevToPrev=prev, prev = temp1, temp1=temp1->next, temp2=temp2->next;
            }
        }
        
        return newHead->next;
    }
};