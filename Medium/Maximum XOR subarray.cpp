

// Question Link :: "https://practice.geeksforgeeks.org/problems/a512e4b2e812b6df2159b19cc7090ffc1ab056dd/1"


// Solution //

class Solution{   
public:


    struct Node{
            
        int bit;
        struct Node *one=NULL, *zero=NULL;
    };
    
    
    int getMax(int num, struct Node *root){
        
        struct Node *node = root;
        int maxi = 0;
        for(int i=31;i>=0;i--){
            int bit = (num >> i)&1;
            
            if( bit==1 && node->zero != NULL ){
                node = node->zero;
                maxi += (1<<i);
            }
            else if( bit==0 && node->one!=NULL ){
                node = node->one;
                maxi += (1<<i);
            }
            else{
                node = (node->zero==NULL)? node->one : node->zero;
            }
        }
        return maxi;
    }
    
    void insert(int num, struct Node *root){
        
        struct Node *node = root;
        for(int i=31;i>=0;i--){
            int bit = (num >> i)&1;
            
            if( bit ){
                if( node->one == NULL ){
                    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
                    newNode->bit = bit;
                    node->one = newNode;
                }
                node = node->one;
            }
            else{
                if( node->zero == NULL ){
                    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
                    newNode->bit = bit;
                    node->zero = newNode;
                }
                node = node->zero;
            }
        }
    }
    
    
    int maxSubarrayXOR(int n, int arr[]){    
        //code here
        int answer=INT_MIN, prefix=0;
        struct Node *root = (struct Node*)malloc(sizeof(struct Node));
        insert(prefix, root);
        
        for(int i=0;i<n;i++){
            prefix = prefix xor arr[i];
            insert(prefix, root);
            answer = max(answer, getMax(prefix, root));
        }
        return answer;
    }
};
