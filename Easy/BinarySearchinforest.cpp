

//   Question Link :: "https://practice.geeksforgeeks.org/problems/ffd66b6a0bf7cefb9987fa455974b6ea5695709e/1#"




// Solution //


Class Solution
    public:
    int find_height(int tree[], int n, int k)
    {
        // code here
        int sum=0,u=get_max(tree,n),l=0,mid = (u+l)/2;
        
        while(l<=u){
            
            sum=0;
            
            for(int i=0;i<n;i++){
                
                if(mid < tree[i]){
                    sum+=(tree[i]-mid);
                }
            }
            
            if(sum == k)
                return mid;
            else if(sum < k)
                u=mid-1;
            else
                l = mid+1;
                
        
            mid = (u+l)/2;
        }
        return -1;
    
    }
    
    
    int get_max(int arr[],int n){
        int m =0;
        for(int i=0;i<n;i++){
            if(arr[i]>m){
                m=arr[i];
            }
        }
        return m;
    }
};