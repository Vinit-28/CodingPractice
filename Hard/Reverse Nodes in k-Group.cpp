

// Question Link :: "https://leetcode.com/problems/reverse-nodes-in-k-group/"


// Solution //

class Solution {
public:
    
    ListNode* reverseNodes(ListNode *node, ListNode *endNode){
        
        if( node == endNode )
            return node;
        
        ListNode *lastNode = reverseNodes(node->next, endNode);
        lastNode->next = node;
        return node;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *next=NULL, *start=NULL, *node = head, *temp, *prevEnd = NULL;
        int counter = 0;
        head = NULL;
        
        while(node != NULL){
            
            start = (start==NULL)? node : start;
            counter += 1;
            
            if( counter%k == 0 ){
                next = node->next;
                temp = reverseNodes(start, node);
                head = (head == NULL)? node : head;
                (prevEnd != NULL)? (prevEnd->next=node) : 0;
                prevEnd = temp, start=NULL, temp->next = next, node = next;
            }
            else{
                node = node->next;
            }
        }
        return head;
    }
};