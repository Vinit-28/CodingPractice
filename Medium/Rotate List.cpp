

// Question Link :: "https://leetcode.com/problems/rotate-list/"



// Solution //

class Solution {
public:
    ListNode *tempNode;
    ListNode* reverseList(ListNode *node, int limit, int index){
        if( index == (limit-1) ) tempNode = node;     
        else{
            ListNode *temp = reverseList(node->next, limit, index+1);
            node->next = temp->next, temp->next = node;
        }
        
        return node;
    }
    
    ListNode *getNode(int index, ListNode *node){
        while(node != NULL && index) node = node->next, index--;
        
        return node;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if( head == NULL || k == 0 ) return head;
        
        ListNode *temp=head, *newHead;
        int len=0;
        
        while(temp != NULL) len++, temp = temp->next;
        k %= len;
        if( k==0 ) return head;
        
        // Reverse the whole LinkedList //
        temp = reverseList(head, len, 0);
        
        // Reverse the first part //
        temp = reverseList(tempNode, k, 0);
        newHead = tempNode;
        
        // Reverse the second part //
        reverseList(temp->next, len, k);
        temp->next = tempNode;
        
        return newHead;
    }
};