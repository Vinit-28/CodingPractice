

// Question Link :: "https://practice.geeksforgeeks.org/problems/maximum-xor-of-two-numbers-in-an-array/1"



// Solution //

struct Node{

    int data;
    struct Node *zero=NULL, *one=NULL;
};

class Solution
{
    public:

    Node *getTrie(int arr[], int n){
        
        struct Node *root = (struct Node*)malloc(sizeof(struct Node));
        
        for(int i=0;i<n;i++){
            struct Node *temp = root;
            for(int j=31;j>=0;j--){
                
                if( !((arr[i]>>j)&1) ){
                    if( temp->zero == NULL ){
                        temp->zero = (struct Node*)malloc(sizeof(Node));
                        temp->zero->data = 0;
                    }
                    temp = temp->zero;  
                }
                else{
                    if( temp->one == NULL ){
                        temp->one = (Node*)malloc(sizeof(Node));
                        temp->one->data = 1;
                    }
                    temp = temp->one;  
                }
            }
        }
        return root;
    }
    
    int max_xor(int arr[] , int n)
    {
        //code here
        int res = 0, curr_res = 0;
        struct Node *root = getTrie(arr, n), *temp = root;
        for(int i=0; i<n; i++, temp=root, curr_res=0){
            
            for(int j=31;j>=0;j--){
                
                int bit = ((arr[i]>>j)&1);
                if( bit == 1 && temp->zero != NULL ){
                    temp = temp->zero;
                    curr_res += (1<<j);
                }
                else if( bit == 0 && temp->one != NULL ){
                    temp = temp->one;
                    curr_res += (1<<j);
                }
                else
                    temp = (temp->zero!=NULL)? temp->zero : temp->one;
            }
            res = max(res, curr_res);
        }
        return res;
    }
};

