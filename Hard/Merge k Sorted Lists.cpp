

// Question Link :: "https://leetcode.com/problems/merge-k-sorted-lists/"


// Solution //

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        map<int, int> hash;
        ListNode *newHead=NULL, *prev=NULL;
        
        for(auto head : lists){
            auto temp = head;
            while(temp!=NULL){
                hash[temp->val]++;
                temp = temp->next;
            }
        }
        
        for(auto p : hash){
            
            for(int i=0;i<p.second;i++){
                ListNode *newNode = new ListNode;
                newNode->val = p.first;
                
                (prev==NULL)? (newHead = prev = newNode) : (prev->next = newNode, prev=newNode);
            }
        }
        
        return newHead;
    }
};