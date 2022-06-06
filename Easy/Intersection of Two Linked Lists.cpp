

// Question Link :: "https://leetcode.com/problems/intersection-of-two-linked-lists/"


// Solution //

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *t1 = headA, *t2 = headB, *ans=NULL;
        int len1=0, len2=0;
        while (t1)
            len1 += 1, t1 = t1->next;
        
        while (t2)
            len2 += 1, t2 = t2->next;
        
        t1=headA, t2=headB;
        if( len1 > len2 ){
            while( len1 > len2 ) t1 = t1->next, len1-=1;
        }
        else if( len1 < len2 ){
            while( len1 < len2 ) t2 = t2->next, len2-=1;
        }
        
        while( t1 ){
            if( t1 == t2 ){
                ans = t1;
                break;
            }
            t1 = t1->next, t2 = t2->next;
        }
        return ans;
    }
};