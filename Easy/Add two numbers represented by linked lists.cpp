

// Question Link :: "https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#"


// Solution //

#include<bits/stdc++.h>

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        int carry = 0;
        vector<int> ll1, ll2, temp;
        Node *t1 = first, *t2 = second, *ans;
        
        while(t1!=NULL || t2!=NULL){
            
            if( t1 != NULL )
                ll1.push_back(t1->data), t1 = t1->next;
           
            if( t2 != NULL )
                ll2.push_back(t2->data), t2 = t2->next;
        }
        
        int i = ll1.size()-1, j = ll2.size()-1;
        
        while(true){
            
            if( i>=0 && j>=0 ){
                if( (ll1[i] + ll2[j] + carry) > 9){
                    
                    carry = ll1[i] + ll2[j] + carry;
                    temp.push_back(carry%10);
                    carry/=10;
                }
                else
                    temp.push_back((ll1[i] + ll2[j] + carry)), carry = 0;
                i-=1, j-=1;
            }
            else if( i<0 && j>=0 ){
                
                if( (ll2[j] + carry) > 9 ){
                    carry  = carry + ll2[j];
                    temp.push_back(carry%10);
                    carry/=10;
                }
                else
                    temp.push_back((ll2[j]+carry)), carry=0;
                j-=1;
            }
            else if( j<0 && i>=0){
                
                if( (ll1[i] + carry) > 9 ){
                    carry  = carry + ll1[i];
                    temp.push_back(carry%10);
                    carry/=10;
                }
                else
                    temp.push_back((ll1[i]+carry)), carry=0;
                i-=1;
            }
            else    
                break;
        }
        if( carry != 0 )
            temp.push_back(carry);
        
        reverse(temp.begin(), temp.end());
        
        ans = t2 = t1 = (struct Node*)malloc(sizeof(struct Node));
      
        for(int i=0;i<temp.size();i++){
            
            t1->data = temp[i];
            t2 = t1;
            t1 = (struct Node*)malloc(sizeof(struct Node));
            t2->next = t1;
            
        }
        t2->next=NULL;
        
        return ans;
    }
};
