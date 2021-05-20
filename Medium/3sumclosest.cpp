


//   Question Link : "https://practice.geeksforgeeks.org/problems/3-sum-closest/1"




//  Solution  //


class Solution{
    public:
    int closest3Sum(int arr[], int n, int x)
    {
        // code here
        int index,i,j,sum,closest_sum=0;
        sort_arr(arr,n);
        
        for(index=0;index<n-2;index++){
            
            j=n-1,i=index+1;
            
            while(i<j){
                
                sum = arr[index] + arr[j] + arr[i];
                
                if(sum == x){
                    return x;
                }
                
                else if(sum < x){
                    i+=1;
                }
                
                else{
                    j-=1;
                }
                
                if( index ==0 || abs(sum-x) < abs(closest_sum-x) ){
                    closest_sum = sum;   
                }   
            }
        }
        return closest_sum;
    }
    
    void sort_arr(int a[],int n){
        
        int temp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                if(a[i] > a[j]){
                    temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
                } 
            }
        }
        
    }
    
};