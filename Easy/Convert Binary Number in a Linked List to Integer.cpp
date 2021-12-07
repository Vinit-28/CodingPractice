

// Question Link :: "https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/"


// Solution //

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        bitset<32> bin(0);
        string binary = "";
        while(head!=NULL)
            binary += (head->val==0)? '0' : '1', head=head->next;
        
        for(int i=0,l=binary.length(); i<l; i++)
            bin[l-i-1] = (binary[i] == '1')? 1 : 0;
        
        return bin.to_ulong();  
    }
};