

// Question Link :: "https://leetcode.com/problems/sort-list/"


// Solution //

class Solution {
public:
    
    // Function to get a node according to an index //     
    ListNode* getNode(ListNode *startNode, int searchIndex, int startIndex){
        
        ListNode *temp = startNode;
        while(startIndex < searchIndex) temp = temp->next, startIndex++;
        
        return temp;
    }
    
    
    // Function to get the length of the linked list //    
    int getLen(ListNode *head){
        
        ListNode *temp = head;
        int len = 0;
        while(temp != NULL) temp = temp->next, len++;
        
        return len;
    }
    
    
    // Function to seperate a list or assigning NULL to last node's next //     
    void makeLastNULL(ListNode *startNode, int start, int end){
        
        ListNode *temp = startNode;
        while(start<(end-1)) temp = temp->next, start++;
        
        temp->next = NULL;
    }
    
    
    // Function to merge two sorted lists //     
    ListNode* mergeTwoSortedLists(ListNode *startNode1, ListNode *startNode2, int start1, int start2, int end1, int end2){
        
        int i=start1, j = start2;
        ListNode *iNode = startNode1, *jNode=startNode2, *newHead = NULL, *prev = NULL;
        
        makeLastNULL(startNode1, start1, end1);
        makeLastNULL(startNode2, start2, end2);
        
        
        while( i<end1 || j<end2 ){
            
            if( (i<end1 && j<end2 && iNode->val < jNode->val) || (j>=end2 && i<end1) ){
                
                (newHead == NULL)? (prev = newHead = iNode) : (prev->next = iNode, prev = iNode);
                i++, iNode = (i < end1)? iNode->next : iNode;
            }
            else{
                (newHead == NULL)? (prev = newHead = jNode) : (prev->next = jNode, prev = jNode);
                j++, jNode = (j < end2)? jNode->next : jNode;
            }
        }
        return newHead;
    }
    
    
    // Function to apply merge sort on a linked list //     
    ListNode* mergeSort(ListNode *startNode, int start, int end){
        
        if( (end-start) <= 1 ) return startNode;
        
        int mid = (start+end)/2;
        ListNode *midNode = getNode(startNode, mid, start);
        
        startNode = mergeSort(startNode, start, mid);
        midNode = mergeSort(midNode, mid, end);
        
        return mergeTwoSortedLists(startNode, midNode, start, mid, mid, end);
    }
    
    
    // Pre-defined Function //     
    ListNode* sortList(ListNode* head) {
        
        int len = getLen(head);
        return mergeSort(head, 0, len);
    }
};