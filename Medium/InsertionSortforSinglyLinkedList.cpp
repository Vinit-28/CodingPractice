

//   Question Link :: "https://practice.geeksforgeeks.org/problems/insertion-sort-for-singly-linked-list/1" 


// Solution //



class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        vector<Node*> arr;
        Node *temp=head_ref;
        int len=0,i,j,key;
        
        while(temp!=NULL){
            arr.push_back(temp);
            temp=temp->next;
            len++;
        }
        
        for(i=0;i<len;i++){
            
            key = arr[i]->data;
            j=i-1;
            
            while(j>=0 && (arr[j]->data) > key ){
                
                arr[j+1]->data = arr[j]->data;
                j-=1;
            }
            
            arr[j+1]->data = key;
            
        }
        return head_ref;
    }
    
};
